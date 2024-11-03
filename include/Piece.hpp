#pragma once
#include <vector>
#include <utility>

enum Color
{
    RED,
    GREEN,
    BLUE,
    YELLOW, 
    WHITE,
    BLACK,
};

enum PieceType {I, J, L, O, S, T, Z};


class Piece {
public:
    Piece();
    virtual ~Piece();
    void move();
    void moveLeft();
    void moveRight();
    void rotate();
    int getX();
    int getY();
    Color getColor();
    std::vector<std::pair<int, int>> getShape();

private:
    int x;
    int y;
    Color color;
    PieceType type;
    std::vector<std::pair<int, int>> shape;
};
