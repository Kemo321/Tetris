#pragma once
#include <SDL2/SDL.h>
#include "Piece.hpp"
#include "Board.hpp"


class Renderer {
public:
    Renderer();
    ~Renderer();
    void render();
    void clear();
    void drawRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
    void drawPiece(Piece* piece);
    void drawBoard(Board* board);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
