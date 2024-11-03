#pragma once
#include <SDL2/SDL.h>
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
    bool isRunning();

private:
    bool running;
    Renderer* renderer;
    Board* board;
    Uint32 last_time;
    Uint32 current_time;
    Uint32 delta_time;
};