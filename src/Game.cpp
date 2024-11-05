#include "Game.hpp"
#include <string>


Game::Game() : running(true), renderer(new Renderer()), board(new Board()), last_time(SDL_GetTicks()), current_time(0), delta_time(0), score(0) {
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

        if (delta_time >= updateInterval && !paused) {
            update();
            last_time = current_time; 
        }
    }

    clean();
}


void Game::update() {
    try {
        board->movePiece();
    } catch (const std::string& e) {
        reset();
        paused = true;
    }
    score += board->cutFullRows();
}


void Game::render() {
    renderer->clear();
    renderer->drawBoard(board);
    renderer->drawPiece(board->moving_piece);
    renderer->drawOutline();
    renderer->drawScore(score);
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
                        if (!paused)
                        board->movePieceLeft();
                        break;
                    case SDLK_RIGHT:
                        if (!paused)
                        board->movePieceRight();
                        break;
                    case SDLK_UP:
                        if (!paused)
                        board->rotatePiece();
                        break;
                    case SDLK_DOWN:
                        if (!paused)
                        board->movePiece();
                        break;
                    case SDLK_SPACE:
                        paused = !paused;
                        break;
                    case SDLK_r:
                        reset();
                        break;
                }
                break;
        }
    }
}

void Game::clean() {
    SDL_Quit();
}

void Game::reset(){
    score = 0;
    board->clear();
    board->addPiece();
    paused = false;
}

bool Game::isRunning() {
    return running;
}
