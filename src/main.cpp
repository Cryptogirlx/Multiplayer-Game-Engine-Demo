#include "./Engine/Engine.h"
#include "./Game/Game.h"
#include <iostream>

int main() {
    std::cout << "Program starting..." << std::endl;
    
    Engine engine; // Create engine
    Game game;     // Create game

    engine.init(); // Initialize engine systems
    engine.run(game); // Start engine loop and run the game

    return 0;      // End program
}
