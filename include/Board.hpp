#pragma once
#include <vector>
#include "Piece.hpp"
#include "Color.hpp"


class Board {

public:
    Board();
    ~Board();
    void addPiece();
    void clear();
    void cutRow(int row);
    void movePiece();
    bool isOccupied(int x, int y);
    int getFullRows();
    Color* getGrid();
    
    friend class Game;

private:
    int rows;
    int cols;
    Color grid[10][20];

protected:
    Piece* moving_piece;
};
