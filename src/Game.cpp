#include "Game.hpp"


Game::Game() : running(true), renderer(new Renderer()), board(new Board()), last_time(SDL_GetTicks()), current_time(0), delta_time(0) {
    board->addPiece();
}

Game::~Game() {
    delete renderer;
    delete board;
}

void Game::run() {
    const int updateInterval = 1000/2; // 1000 ms = 1 second
    last_time = SDL_GetTicks();

    while (running) {
        // Handle events continuously
        handleEvents();
        render();

        current_time = SDL_GetTicks();
        delta_time = current_time - last_time;

        if (delta_time >= updateInterval) {
            update();
            last_time = current_time; 
        }
    }

    clean();
}


void Game::update() {
    board->movePiece();
}


void Game::render() {
    renderer->clear();
    renderer->drawBoard(board);
    renderer->drawPiece(board->moving_piece);
    renderer->render();
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        board->moving_piece->moveLeft();
                        break;
                    case SDLK_RIGHT:
                        board->moving_piece->moveRight();
                        break;
                    case SDLK_UP:
                        board->moving_piece->rotate();
                        break;
                }
                break;
        }
    }
}

void Game::clean() {
    SDL_Quit();
}

bool Game::isRunning() {
    return running;
}
