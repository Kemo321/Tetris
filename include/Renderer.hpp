#pragma once
#include "Board.hpp"


class Renderer {
public:
    Renderer();
    ~Renderer();
    void render();
    void clear();
    void drawRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
    void drawLine(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
    void drawOutline();
    void drawPiece(Piece* piece);
    void drawBoard(Board* board);
    void drawScore(int score);
    void drawNumber(int x, int y, int number);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
