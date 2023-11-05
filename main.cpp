#include <common.h>
#include <defs.h>
#include <Grid.h>
#include <Disk.h>
#include <Game.h>
#include <GameRenderer.h>

bool initSDL(SDL_Window*& window, SDL_Renderer*& renderer);

int main(int argsc, char* argv[]) {
    //POINTER AND CONSTS
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    Grid* grid = NULL;
    Game* game = NULL;
    GameRenderer* gameRenderer = NULL;
    int** map = NULL;
    const int gridSize = 48;
    const int highlightOutlineWidth = 4;
    const int numberOfRows = 8;
    const int numberOfCols = 5;
    const int sleepTime = 80;

    //INIT
    if (!initSDL(window, renderer)) {
        return 1;
    }
    SDL_SetWindowTitle(window, "Reversi");

    bool quit = false;
    SDL_Event e;
    int mouseX = 0;
    int mouseY = 0;
    std::set<Disk> disks;

    grid = new Grid(renderer, gridSize, numberOfRows, numberOfCols);
    grid->setFillColor(Color(133, 200, 244,255));

    game = new Game(numberOfRows, numberOfCols);
    map = game->getMap();
    
    gameRenderer = new GameRenderer(renderer, numberOfRows, numberOfCols);
    gameRenderer->renderDisks(map, disks);

    if (game->getCurrentMove() == BLACK_DISK) {
        std::cout << "Black is moving.. \n";
    }
    else {
        std::cout << "White is moving.. \n";
    }

    while (!quit) {
        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            if (e.type == SDL_MOUSEMOTION) {
                mouseX = e.button.x;
                mouseY = e.button.y;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    int mouseClickedX = e.button.x;
                    int mouseClickedY = e.button.y;
                    if (grid->isWithinGrid(mouseClickedX, mouseClickedY) && game->isValidMove(mouseClickedX / grid->getGridSize(), mouseClickedY / grid->getGridSize(), game->getCurrentMove())) {
                        if (game->insertDisk(mouseClickedX / grid->getGridSize(), mouseClickedY / grid->getGridSize(), game->getCurrentMove())) {
                            map = game->getMap();
                            game->renderMapOnConsole();
                            if (game->getCurrentMove() == BLACK_DISK) {
                                std::cout << "Black is moving.. \n";
                            }
                            else {
                                std::cout << "White is moving.. \n";
                            }
                            gameRenderer->renderDisks(map, disks);
                        }
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }

        if (game->isWonBy() == BLACK_DISK) {
            
        }
        else if (game->isWonBy() == WHITE_DISK) {

        }
        
        grid->draw();
        gameRenderer->renderValidMoves(game->getValidMoves(game->getCurrentMove()));
        gameRenderer->renderCursorHighlight(mouseX, mouseY, gridSize, highlightOutlineWidth);
        for (auto disk : disks) {
            disk.draw(gridSize);
        }

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}

bool initSDL(SDL_Window*& window, SDL_Renderer*& renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Grid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}