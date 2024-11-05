#include "Board.hpp"
#include "Piece.hpp"
#include "Constants.hpp"
#include <string>


Board::Board() : rows(20), cols(10)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = BLACK;
        }
    }
}

Board::~Board() = default;

void Board::addPiece() {
    moving_piece = new Piece();
}

void Board::clear() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = BLACK;
        }
    }
    delete moving_piece;
    moving_piece = nullptr;
}

void Board::cutRow(int row) {
    for (int i = row; i > 0; i--) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = grid[i - 1][j];
        }
    }
    for (int j = 0; j < cols; j++) {
        grid[0][j] = BLACK;
    }
}

void Board::cutFullRows() {
    for (const int& row : getFullRows()) {
        cutRow(row);
    }
}

void Board::movePiece() {
    if (moving_piece == nullptr) {
        return;
    }
    std::vector<std::pair<int, int>> shape = moving_piece->getShape();
    for (int i = 0; i < shape.size(); i++) {
        int x = moving_piece->getX() + shape[i].first;
        int y = moving_piece->getY() + shape[i].second;
        if (y + 1 >= rows || isOccupied(x, y + 1)) {
            for (int i = 0; i < shape.size(); i++) {
                int x = moving_piece->getX() + shape[i].first;
                int y = moving_piece->getY() + shape[i].second;
                grid[y][x] = moving_piece->getColor();
            }
            delete moving_piece;
            moving_piece = new Piece();
            for (int i = 0; i < shape.size(); i++) {
                int x = moving_piece->getX() + shape[i].first;
                int y = moving_piece->getY() + shape[i].second;
                if (isOccupied(x, y)) {
                    throw std::string("Game Over");
                }
            }
            return;
        }
    }
    moving_piece->move();
}

bool Board::isOccupied(int x, int y) {
    return grid[y][x] != BLACK;
}

std::vector<int> Board::getFullRows(){
    std::vector<int> full_rows;
    for (int i = 0; i < rows; i++) {
        bool full = true;
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == BLACK) {
                full = false;
                break;
            }
        }
        if (full) {
            full_rows.push_back(i);
        }
    }
    return full_rows;
}

Color* Board::getGrid() {
    return *grid;
}
