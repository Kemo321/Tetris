#include <gtest/gtest.h>
#include "Game.hpp"


class GameTest : public ::testing::Test {
    protected:
    GameTest() {
        game = new Game();
    }

    ~GameTest() override {
        delete game;
    }

    void TearDown() override {
        game->reset();
    }

    Game* game;
};

TEST_F(GameTest, Run) {
    game->run();
    ASSERT_TRUE(true);
}

TEST_F(GameTest, Update) {
    game->update();
    ASSERT_TRUE(true);
}

TEST_F(GameTest, Render) {
    game->render();
    ASSERT_TRUE(true);
}

TEST_F(GameTest, HandleEvents) {
    game->handleEvents();
    ASSERT_TRUE(true);
}

TEST_F(GameTest, Clean) {
    game->clean();
    ASSERT_TRUE(true);
}

TEST_F(GameTest, Reset) {
    game->reset();
    ASSERT_TRUE(true);
}

TEST_F(GameTest, IsRunning) {
    ASSERT_TRUE(game->isRunning());
}

TEST_F(GameTest, Destructor) {
    delete game;
    ASSERT_TRUE(true);
}
