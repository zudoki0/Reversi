#include <common.h>
#include <defs.h>
#include <GridRenderer.h>
#include <Disk.h>
#include <DiskRenderer.h>
#include <TextRenderer.h>
#include <ReversiBoardBuilder.h>
#include <ReversiGameManager.h>
#include <ReversiValidMoveSearcher.h>
#include <Board.h>
#include <MoveCommand.h>
#include <CursorHighlightRenderer.h>
#include <ValidMoveRenderer.h>
#include <IRenderer.h>

bool initSDL(SDL_Window*& window, SDL_Renderer*& renderer);

int main(int argsc, char* argv[]) {
    //POINTER AND CONSTS
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    TTF_Font* font = NULL;
    Board* board = NULL;
    BoardBuilder* boardBuilder = NULL;
    ReversiGameManager* reversiGameManager = NULL;
    ReversiValidMoveSearcher* reversiValidMoveSearcher = NULL;
    MoveCommand* moveCommand = NULL;
    const int gridSize = 48;
    const int highlightOutlineWidth = 4;
    const int sleepTime = 25;
    const int reversiGameWidthAndHeight = 8;
    const int fontSize = 64;
    const SDL_Rect textContainer = { 0,384,384,116 };
    const SDL_Color blackColor = { 0,0,0,255 };
    const SDL_Color whiteColor = { 255,255,255,255 };
    const SDL_Color lightBlueColor = { 0,128,255,255 };

    //INIT WINDOW, RENDERER AND FONT
    if (!initSDL(window, renderer)) {
        return 1;
    }
    SDL_SetWindowTitle(window, "Reversi");
    font = TTF_OpenFont("./fonts/ToThePointRegular-n9y4.ttf", fontSize);
    if (font == NULL) {
        std::cout << "No font was found! \n";
        return 1;
    }

    //INIT TEMP VALUES FOR WINDOW
    bool quit = false;
    SDL_Event e;
    int mouseX = 0;
    int mouseY = 0;

    //INIT GAME
    boardBuilder = new ReversiBoardBuilder();
    board = new Board(boardBuilder->build());
    reversiGameManager = new ReversiGameManager(*board);
    reversiValidMoveSearcher = new ReversiValidMoveSearcher(*board);

    //INIT OBJECT RENDERERS
    std::vector<IRenderer*> renderers;
    renderers.push_back(new GridRenderer(renderer, gridSize, reversiGameWidthAndHeight, reversiGameWidthAndHeight, lightBlueColor, blackColor));
    renderers.push_back(new CursorHighlightRenderer(renderer, gridSize, highlightOutlineWidth));
    renderers.push_back(new TextRenderer(renderer, font, "Waiting..", textContainer, whiteColor));
    renderers.push_back(new DiskRenderer(renderer, *board, gridSize));
    renderers.push_back(new ValidMoveRenderer(renderer, reversiValidMoveSearcher, *board, gridSize, reversiGameManager->getCurrentPlayer()));

    //INIT COMMANDS
    moveCommand = new MoveCommand(*reversiGameManager, 0, 0, *reversiValidMoveSearcher);

    while (!quit) {
        // Clear the screen
        SDL_SetRenderDrawColor(renderer, blackColor.r, blackColor.g, blackColor.b, blackColor.a);
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
                    delete moveCommand;
                    moveCommand = new MoveCommand(*reversiGameManager, e.button.x / gridSize, e.button.y / gridSize, *reversiValidMoveSearcher);
                    moveCommand->execute();
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }

        
        for (auto& r : renderers) {
            if (TextRenderer* textRenderer = dynamic_cast<TextRenderer*>(r)) {
                
                if (reversiGameManager->getWinner() == BlackWin) {
                    textRenderer->changeText("Black won!");
                }
                else if (reversiGameManager->getWinner() == WhiteWin) {
                    textRenderer->changeText("White won!");
                }
                else if (reversiGameManager->getWinner() == Draw) {
                    textRenderer->changeText("It's Draw!");
                }
                else if (reversiGameManager->getCurrentPlayer().getType() == BLACK) {
                    textRenderer->changeText("Black is moving..");
                }
                else if (reversiGameManager->getCurrentPlayer().getType() == WHITE) {
                    textRenderer->changeText("White is moving..");
                }
            }
            else if (CursorHighlightRenderer* cursorRenderer = dynamic_cast<CursorHighlightRenderer*>(r)) {
                cursorRenderer->setMousePos(mouseX, mouseY);
            }
            else if (ValidMoveRenderer* validMoveRenderer = dynamic_cast<ValidMoveRenderer*>(r)) {
                validMoveRenderer->setPlayer(reversiGameManager->getCurrentPlayer());
            }

            r->render();
        }

  
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        SDL_RenderPresent(renderer);
    }

    //DESTROY ALL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    delete board;
    delete boardBuilder;
    delete moveCommand;
    delete reversiGameManager;
    delete reversiValidMoveSearcher;
    for (IRenderer* renderer : renderers) {
        delete renderer;
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