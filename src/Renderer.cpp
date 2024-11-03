#include "Renderer.hpp"
#include "Constants.hpp"
#include "Color.hpp"
#include <iostream>


Renderer::Renderer() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
    window = SDL_CreateWindow("SDL2 Window", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
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
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}

void Renderer::drawRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect rect = {x, y, w, h};
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::drawPiece(Piece* piece) {
    std::vector<std::pair<int, int>> shape = piece->getShape();
    for (int i = 0; i < shape.size(); i++) {
        int x = piece->getX() + shape[i].first;
        int y = piece->getY() + shape[i].second;
        Color color = piece->getColor();
        drawRect(x * 20, y * 20, 40, 40, getR(color), getG(color), getB(color));
    }
}

void Renderer::drawBoard(Board* board) {
    Color* grid = board->getGrid();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i * 10 + j] != BLACK) {
                Color c = grid[i * 10 + j];
                drawRect(j * 20, i * 20, 40, 40, getR(c), getG(c), getB(c));
            }
        }
    }   
}
