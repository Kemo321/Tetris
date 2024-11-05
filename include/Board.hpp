#pragma once
#include <vector>
#include "Color.hpp"


class Board {

public:
    Board();
    ~Board();
    void addPiece();
    void clear();
    void cutRow(int row);
    void movePiece();
    void rotatePiece();
    void movePieceLeft();
    void movePieceRight();
    bool isOccupied(int x, int y);
    int cutFullRows();

    Piece* getMovingPiece();
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
