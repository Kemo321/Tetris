#include "Board.hpp"
#include "Piece.hpp"
#include "Constants.hpp"
#include <string>


Board::Board() : rows(20), cols(10), moving_piece(nullptr)
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

int Board::cutFullRows() {
    std::vector<int> full_rows = getFullRows();
    int score = full_rows.empty() ? 0 : 100;
    for (const int& row : full_rows) {
        cutRow(row);
        score *= 2;
    }
    return score;
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
            shape = moving_piece->getShape();
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

void Board::rotatePiece() {
    if (moving_piece == nullptr) {
        return;
    }
    moving_piece->rotate();
    std::vector<std::pair<int, int>> shape = moving_piece->getShape();
    for (int i = 0; i < shape.size(); i++) {
        int x = moving_piece->getX() + shape[i].first;
        int y = moving_piece->getY() + shape[i].second;
        if (x < 0 || x >= cols || y < 0 || y >= rows || isOccupied(x, y)) {
            moving_piece->rotateBack();
            return;
        }
    }
}

void Board::movePieceLeft() {
    if (moving_piece == nullptr) {
        return;
    }
    std::vector<std::pair<int, int>> shape = moving_piece->getShape();
    for (int i = 0; i < shape.size(); i++) {
        int x = moving_piece->getX() + shape[i].first;
        int y = moving_piece->getY() + shape[i].second;
        if (x - 1 < 0 || isOccupied(x - 1, y)) {
            return;
        }
    }
    moving_piece->moveLeft();
}

void Board::movePieceRight() {
    if (moving_piece == nullptr) {
        return;
    }
    std::vector<std::pair<int, int>> shape = moving_piece->getShape();
    for (int i = 0; i < shape.size(); i++) {
        int x = moving_piece->getX() + shape[i].first;
        int y = moving_piece->getY() + shape[i].second;
        if (x + 1 >= cols || isOccupied(x + 1, y)) {
            return;
        }
    }
    moving_piece->moveRight();
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
