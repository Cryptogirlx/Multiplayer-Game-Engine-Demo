#include "./Engine/Engine.h"
#include "./Game/Game.h"

int main() {
    Engine engine; // Create engine
    Game game;     // Create game

    engine.init(); // Initialize engine systems
    engine.run(game); // Start engine loop and run the game

    return 0;      // End program
}
