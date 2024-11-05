#include <gtest/gtest.h>
#include "Board.hpp"


class BoardTest : public ::testing::Test {
protected:
    BoardTest() {
        board = new Board();
    }

    ~BoardTest() override {
        delete board;
    }

    void TearDown() override {
        board->clear();
    }

    Board* board;
};

TEST_F(BoardTest, AddPiece) {
    board->addPiece();
    Piece* piece = board->getMovingPiece();
    ASSERT_NE(piece, nullptr);
}

TEST_F(BoardTest, MovePiece) {
    board->addPiece();
    Piece* piece = board->getMovingPiece();
    int x = piece->getX();
    int y = piece->getY();
    board->movePiece();
    ASSERT_EQ(piece->getX(), x);
    ASSERT_EQ(piece->getY(), y + 1);
}

TEST_F(BoardTest, MovePieceLeft) {
    board->addPiece();
    Piece* piece = board->getMovingPiece();
    int x = piece->getX();
    int y = piece->getY();
    board->movePieceLeft();
    ASSERT_EQ(piece->getX(), x - 1);
    ASSERT_EQ(piece->getY(), y);
}

TEST_F(BoardTest, MovePieceRight) {
    board->addPiece();
    Piece* piece = board->getMovingPiece();
    int x = piece->getX();
    int y = piece->getY();
    board->movePieceRight();
    ASSERT_EQ(piece->getX(), x + 1);
    ASSERT_EQ(piece->getY(), y);
}


TEST_F(BoardTest, CutRow) {
    board->addPiece();
    Piece* piece = board->getMovingPiece();
    std::vector<std::pair<int, int>> shape = piece->getShape();
    for (int i = 0; i < shape.size(); i++) {
        int x = piece->getX() + shape[i].first;
        int y = piece->getY() + shape[i].second;
        board->cutRow(y);
    }
    Color* grid = board->getGrid();
    for (int i = 0; i < 10; i++) {
        ASSERT_EQ(grid[i], BLACK);
    }
}

TEST_F(BoardTest, CutFullRows) {
    board->addPiece();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            board->getGrid()[i * 10 + j] = WHITE;
        }
    }
    int score = board->cutFullRows();
    ASSERT_EQ(score, 1600);
}

TEST_F(BoardTest, IsOccupied) {
    board->addPiece();
    Piece* piece = board->getMovingPiece();
    std::vector<std::pair<int, int>> shape = piece->getShape();
    for (int i = 0; i < shape.size(); i++) {
        int x = piece->getX() + shape[i].first;
        int y = piece->getY() + shape[i].second;
        ASSERT_FALSE(board->isOccupied(x, y));
    }
}

TEST_F(BoardTest, GetFullRows) {
    board->addPiece();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            board->getGrid()[i * 10 + j] = WHITE;
        }
    }
    std::vector<int> full_rows = board->getFullRows();
    ASSERT_EQ(full_rows.size(), 4);
}

TEST_F(BoardTest, GetGrid) {
    Color* grid = board->getGrid();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            ASSERT_EQ(grid[i * 10 + j], BLACK);
        }
    }
}

TEST_F(BoardTest, Clear) {
    board->addPiece();
    board->clear();
    Piece* piece = board->getMovingPiece();
    ASSERT_EQ(piece, nullptr);
    Color* grid = board->getGrid();
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            ASSERT_EQ(grid[i * 10 + j], BLACK);
        }
    }
}

TEST_F(BoardTest, Destructor) {
    delete board;
    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
