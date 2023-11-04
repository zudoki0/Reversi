#include <common.h>
#include <defs.h>
#include <Grid.h>
#include <Disk.h>
#include <Game.h>

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

void change(int **map, std::set<Disk>& disks, SDL_Renderer* renderer) {
    disks.clear();
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[i][j] == BLACK_DISK) {
                Disk disk = Disk(renderer, i, j, DiskType::BLACK, 44);
                disks.insert(disk);
            }
            else if (map[i][j] == WHITE_DISK) {
                Disk disk = Disk(renderer, i, j, DiskType::WHITE, 44);
                disks.insert(disk);
            }
        }
    }
}

int main(int argsc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    Grid* grid;
    Game* game;
    int** map;

    if (!initSDL(window, renderer)) {
        return 1;
    }

    SDL_SetWindowTitle(window, "Reversi");

    bool quit = false;
    bool clicked = false;
    SDL_Event e;
    int mouseX = 0;
    int mouseY = 0;
    int mouseClickedX = 0;
    int mouseClickedY = 0;
    std::set<Disk> disks;

    grid = new Grid(renderer, 48,8,8);
    grid->setFillColor(Color(133, 200, 244,255));

    game = new Game(8, 8);
    map = game->getMap();
    change(map, disks, renderer);

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
                    mouseClickedX = e.button.x;
                    mouseClickedY = e.button.y;
                    if (grid->isWithinGrid(mouseClickedX, mouseClickedY) && game->isValidMove(mouseClickedX / grid->getGridSize(), mouseClickedY / grid->getGridSize(), game->getCurrentMove())) {
                        if (game->insertDisk(mouseClickedX / grid->getGridSize(), mouseClickedY / grid->getGridSize(), game->getCurrentMove())) {
                            map = game->getMap();
                            if (game->getCurrentMove() == BLACK_DISK) {
                                std::cout << "Black is moving.. \n";
                            }
                            else {
                                std::cout << "White is moving.. \n";
                            }
                            change(map, disks, renderer);
                        }
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(80));
        }

        if (game->isWonBy() != 0) {
            if (game->isWonBy() == BLACK_DISK) {
                std::cout << "Black won!\n";
            }
            else {
                std::cout << "White won!\n";
            }
        }
        
        if (grid->isWithinGrid(mouseX, mouseY)) {
            grid->draw(mouseX, mouseY, 4);
        }
        else {
            grid->draw();
        }


        for (auto disk : disks) {
            disk.draw(48);
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
        // Update the screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;
}