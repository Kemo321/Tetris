#pragma once
#include "Renderer.hpp"
#include "Board.hpp"


class Game {
public:
    Game();
    ~Game();
    void run();
    void update();
    void render();
    void handleEvents();
    void clean();
    void reset();
    bool isRunning();

private:
    int score;
    bool paused;
    bool running;
    Renderer* renderer;
    Board* board;
    Uint32 last_time;
    Uint32 current_time;
    Uint32 delta_time;
};