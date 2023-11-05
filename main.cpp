#include <common.h>
#include <defs.h>
#include <Grid.h>
#include <Disk.h>
#include <Game.h>
#include <GameRenderer.h>
#include <TextRenderer.h>

bool initSDL(SDL_Window*& window, SDL_Renderer*& renderer);

int main(int argsc, char* argv[]) {
    //POINTER AND CONSTS
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    TTF_Font* font = NULL;
    Grid* grid = NULL;
    Game* game = NULL;
    GameRenderer* gameRenderer = NULL;
    TextRenderer* textRenderer = NULL;
    const int gridSize = 48;
    const int highlightOutlineWidth = 4;
    const int numberOfRows = 8;
    const int numberOfCols = 8;
    const int sleepTime = 50;

    //INIT
    if (!initSDL(window, renderer)) {
        return 1;
    }
    SDL_SetWindowTitle(window, "Reversi");
    font = TTF_OpenFont("./fonts/ToThePointRegular-n9y4.ttf", 64);
    if (font == NULL) {
        std::cout << "No font was found! \n";
        return 1;
    }

    bool quit = false;
    SDL_Event e;
    int mouseX = 0;
    int mouseY = 0;
    std::set<Disk> disks;
    
    grid = new Grid(renderer, gridSize, numberOfRows, numberOfCols);
    grid->setFillColor(Color(133, 200, 244,255));

    game = new Game(numberOfRows, numberOfCols);
    int **map = game->getMap();
    
    gameRenderer = new GameRenderer(renderer, numberOfRows, numberOfCols);
    gameRenderer->renderDisks(map, disks);

    textRenderer = new TextRenderer(renderer);

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
                    if (grid->isWithinGrid(e.button.x , e.button.y) && game->isValidMove(e.button.x / grid->getGridSize(), e.button.y / grid->getGridSize(), game->getCurrentMove())) {
                        if (game->insertDisk(e.button.x / grid->getGridSize(), e.button.y / grid->getGridSize(), game->getCurrentMove())) {
                            gameRenderer->renderDisks(map, disks);
                        }
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }

        grid->draw();
        gameRenderer->renderValidMoves(game->getValidMoves(game->getCurrentMove()));
        gameRenderer->renderCursorHighlight(mouseX, mouseY, gridSize, highlightOutlineWidth);
        for (auto disk : disks) {
            disk.draw(gridSize);
        }

        
        if (game->isWonBy() == BLACK_DISK) {
            textRenderer->renderText(font, "Black won!");
        }
        else if (game->isWonBy() == WHITE_DISK) {
            textRenderer->renderText(font, "White won!");
        }

        if (game->getCurrentMove() == BLACK_DISK && game->isWonBy() == 0) {
            textRenderer->renderText(font, "Black is moving..");
        }
        else if (game->isWonBy() == 0) {
            textRenderer->renderText(font, "White is moving..");
        }
  
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        // Update the screen
        SDL_RenderPresent(renderer);
    }

    //Destroy all
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    if (grid != NULL) {
        delete grid;
    }
    if (game != NULL) {
        delete game;
    }
    if (gameRenderer != NULL) {
        delete gameRenderer;
    }
    if (textRenderer != NULL) {
        delete textRenderer;
    }

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

    if (TTF_Init() < 0)
    {
        printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());
        return false;
    }

    return true;
}