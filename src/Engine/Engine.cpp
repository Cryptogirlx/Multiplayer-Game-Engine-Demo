#include "Engine.h"
#include "../Game/Game.h"

void Engine::init() {
    isRunning = true;
    window.create(sf::VideoMode(sf::Vector2u(800, 600)), "Quantum Runner", sf::Style::Default);
}

void Engine::run(Game& game){
    game.start();
    while (isRunning && window.isOpen()) {

         // --- Event handling ---
        while (auto event = window.pollEvent()) {   
            if (event->type == sf::Sensor::Type::Closed) { 
                window.close();     
                stop();   
            }
        }

        // --- Update the game state ---
        game.update();

        // --- Render the frame ---
        window.clear(sf::Color::Black); // Clear screen to black
        game.render();  // Render game objects
        window.display();     // Show the drawn frame
    }
}

void Engine::stop() {
    isRunning = false;
}

