#pragma once

class Game {
    public:
    void start(); // Start the game
    void update(); // Update the game
    void render(); // Render the game
   
    private:
    bool isRunning;
};