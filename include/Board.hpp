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
    void cutFullRows();
    void movePiece();
    bool isOccupied(int x, int y);
    std::vector<int> getFullRows();
    Color* getGrid();
    
    friend class Game;

private:
    int rows;
    int cols;
    Color grid[20][10];

protected:
    Piece* moving_piece;
};
