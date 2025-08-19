#pragma once
class Game;

class Engine {
public:
    void init();            // Initialize engine systems
    void run(Game& game);   // Run the engine with a game
private:
    bool isRunning;
};
