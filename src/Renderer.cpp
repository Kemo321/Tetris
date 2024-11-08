#include "Renderer.hpp"
#include "Constants.hpp"
#include "Color.hpp"
#include <iostream>


Renderer::Renderer() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    window = SDL_CreateWindow("Tetris", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::render() {
    SDL_RenderPresent(renderer);
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void Renderer::drawRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::drawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Renderer::drawOutline(){
    for (int i = 0; i < 21; i++){
        drawLine(50, i * 30 + 50, 350, i * 30 + 50, 120, 120, 0);
    }
    for (int i = 0; i < 11; i++){
        drawLine(i * 30 + 50, 50, i * 30 + 50, 650, 120, 120, 0);
    }
}

void Renderer::drawPiece(Piece* piece) {
    std::vector<std::pair<int, int>> shape = piece->getShape();
    for (int i = 0; i < shape.size(); i++) {
        int x = piece->getX() + shape[i].first;
        int y = piece->getY() + shape[i].second;
        Color color = piece->getColor();
        drawRect(x * 30 + 50, y * 30 + 50, 30, 30, getR(color), getG(color), getB(color));
    }
}

void Renderer::drawBoard(Board* board) {
    Color* grid = board->getGrid();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            Color c = grid[i * 10 + j];
            drawRect(j * 30 + 50, i * 30 + 50, 30, 30, getR(c), getG(c), getB(c));
        }
    }   
}

void Renderer::drawScore(int score) {
    std::string str_score = std::to_string(score);
    
    for (int i = 0 ; 5 - str_score.size() != 0; i++)
        str_score = "0" + str_score;
    
    for (int i = 0; i < 5; i++) {
        drawNumber(70 + 60 * i, 15, str_score[i] - '0');
    }
}

void Renderer::drawNumber(int x, int y, int number){
    switch(number){
        case 0:
            drawLine(x, y, x + 20, y, 0, 0, 0);
            drawLine(x, y, x, y + 30, 0, 0, 0);
            drawLine(x + 20, y, x + 20, y + 30, 0, 0, 0);
            drawLine(x, y + 30, x + 20, y + 30, 0, 0, 0);
            break;
        case 1:
            drawLine(x + 10, y, x + 10, y + 30, 0, 0, 0);
            break;
        case 2:
            drawLine(x, y, x + 20, y, 0, 0, 0);
            drawLine(x + 20, y, x + 20, y + 15, 0, 0, 0);
            drawLine(x, y + 15, x + 20, y + 15, 0, 0, 0);
            drawLine(x, y + 15, x, y + 30, 0, 0, 0);
            drawLine(x, y + 30, x + 20, y + 30, 0, 0, 0);
            break;
        case 3:
            drawLine(x, y, x + 20, y, 0, 0, 0);
            drawLine(x + 20, y, x + 20, y + 30, 0, 0, 0);
            drawLine(x, y + 15, x + 20, y + 15, 0, 0, 0);
            drawLine(x, y + 30, x + 20, y + 30, 0, 0, 0);
            break;
        case 4:
            drawLine(x, y, x, y + 15, 0, 0, 0);
            drawLine(x, y + 15, x + 20, y + 15, 0, 0, 0);
            drawLine(x + 10, y, x + 10, y + 30, 0, 0, 0);
            break;
        case 5:
            drawLine(x, y, x + 20, y, 0, 0, 0);
            drawLine(x, y, x, y + 15, 0, 0, 0);
            drawLine(x, y + 15, x + 20, y + 15, 0, 0, 0);
            drawLine(x + 20, y + 15, x + 20, y + 30, 0, 0, 0);
            drawLine(x, y + 30, x + 20, y + 30, 0, 0, 0);
            break;
        case 6:
            drawLine(x, y, x + 20, y, 0, 0, 0);
            drawLine(x, y, x, y + 30, 0, 0, 0);
            drawLine(x, y + 15, x + 20, y + 15, 0, 0, 0);
            drawLine(x + 20, y + 15, x + 20, y + 30, 0, 0, 0);
            drawLine(x, y + 30, x + 20, y + 30, 0, 0, 0);
            drawLine(x, y + 15, x, y + 30, 0, 0, 0);
            break;
        case 7:
            drawLine(x, y, x + 20, y, 0, 0, 0);
            drawLine(x + 20, y, x + 20, y + 30, 0, 0, 0);
            break;
        case 8:
            drawLine(x, y, x + 20, y, 0, 0, 0);
            drawLine(x, y, x, y + 30, 0, 0, 0);
            drawLine(x, y + 15, x + 20, y + 15, 0, 0, 0);
            drawLine(x + 20, y + 15, x + 20, y + 30, 0, 0, 0);
            drawLine(x, y + 30, x + 20, y + 30, 0, 0, 0);
            drawLine(x + 20, y, x + 20, y + 30, 0, 0, 0);
            break;
        case 9:
            drawLine(x, y, x + 20, y, 0, 0, 0);
            drawLine(x, y, x, y + 15, 0, 0, 0);
            drawLine(x, y + 15, x + 20, y + 15, 0, 0, 0);
            drawLine(x + 20, y + 15, x + 20, y + 30, 0, 0, 0);
            drawLine(x, y + 30, x + 20, y + 30, 0, 0, 0);
            drawLine(x + 20, y, x + 20, y + 30, 0, 0, 0);
            break;
    }
}