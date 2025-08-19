#pragma once
#include "Player.h"

class Game {
    public:
    void start(); // Start the game
    void update(); // Update the game
    void render(); // Render the game
   
    private:
    bool isRunning;
    Player player;
};