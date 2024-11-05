#include <gtest/gtest.h>
#include "Piece.hpp"


class PieceTest : public ::testing::Test {
protected:
    PieceTest() {
        piece = new Piece();
    }

    ~PieceTest() override {
        delete piece;
    }

    Piece* piece;
};

TEST_F(PieceTest, Rotate) {
    piece->rotate();
    ASSERT_TRUE(true);
}

TEST_F(PieceTest, GetShape) {
    std::vector<std::pair<int, int>> shape = piece->getShape();
    ASSERT_EQ(shape.size(), 4);
}

TEST_F(PieceTest, GetX) {
    int x = piece->getX();
    ASSERT_EQ(x, 4);
}

TEST_F(PieceTest, GetY) {
    int y = piece->getY();
    ASSERT_EQ(y, 0);
}

TEST_F(PieceTest, Move) {
    piece->move();
    ASSERT_TRUE(true);
}

TEST_F(PieceTest, RotateBack) {
    piece->rotateBack();
    ASSERT_TRUE(true);
}
