#include "Piece.hpp"


Piece::Piece() : x(4), y(0), color(static_cast<Color>(rand() % 5)), type(static_cast<PieceType>(rand() % 7)) {
    shape = std::vector<std::pair<int, int>>();
    switch (this->type) {
       case I:
           shape.push_back(std::make_pair(0, 0));
           shape.push_back(std::make_pair(0, 1));
           shape.push_back(std::make_pair(0, 2));
           shape.push_back(std::make_pair(0, 3));
           break;
        case J:
            shape.push_back(std::make_pair(0, 0));
            shape.push_back(std::make_pair(0, 1));
            shape.push_back(std::make_pair(0, 2));
            shape.push_back(std::make_pair(1, 2));
            break;
        case L:
            shape.push_back(std::make_pair(0, 0));
            shape.push_back(std::make_pair(0, 1));
            shape.push_back(std::make_pair(0, 2));
            shape.push_back(std::make_pair(-1, 2));
            break;
        case O:
            shape.push_back(std::make_pair(0, 0));
            shape.push_back(std::make_pair(0, 1));
            shape.push_back(std::make_pair(1, 0));
            shape.push_back(std::make_pair(1, 1));
            break;
        case S: 

            shape.push_back(std::make_pair(0, 0));
            shape.push_back(std::make_pair(1, 0));
            shape.push_back(std::make_pair(-1, 1));
            shape.push_back(std::make_pair(0, 1));
            break;
        case T:
            shape.push_back(std::make_pair(0, 0));
            shape.push_back(std::make_pair(-1, 1));
            shape.push_back(std::make_pair(0, 1));
            shape.push_back(std::make_pair(1, 1));
            break;  
        case Z:
            shape.push_back(std::make_pair(0, 0));
            shape.push_back(std::make_pair(-1, 0));
            shape.push_back(std::make_pair(0, 1));
            shape.push_back(std::make_pair(1, 1));
            break;
    }
}

Piece::~Piece() {
}

void Piece::move() {
    y++;
}

void Piece::rotate() {
    for (std::pair<int, int>& point : shape) {
        int temp = point.first;
        point.first = -point.second;
        point.second = temp;
    }
}

int Piece::getX() {
    return x;
}

int Piece::getY() {
    return y;
}

Color Piece::getColor() {
    return color;
}

std::vector<std::pair<int, int>> Piece::getShape() {
    return shape;
}

void Piece::moveLeft() {
    x--;
}

void Piece::moveRight() {
    x++;
}
