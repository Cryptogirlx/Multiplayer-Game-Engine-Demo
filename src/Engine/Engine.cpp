#include "Engine.h"
#include "../Game/Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp> // For sf::Event

// Initialize engine and window
void Engine::init() {
  isRunning = true;
  // SFML 3.x VideoMode takes a Vector2u
  window.create(sf::VideoMode(sf::Vector2u(800, 600)), "Quantum Runner");
  window.setFramerateLimit(60); // optional
}

// Run the main game loop
void Engine::run(Game &game) {
  game.start();

  while (isRunning && window.isOpen()) {
    // --- Event Handling ---
    while (auto maybeEvent = window.pollEvent()) {
      // SFML 3.x: events are std::optional<sf::Event>
      if (maybeEvent->is<sf::Event::Closed>()) { // check if it's a Close event
        window.close();
        stop();
      }
    }

    // --- Update Game Logic ---
    game.update();

    // --- Render ---
    window.clear();      // clear previous frame
    game.render(window); // render game objects
    window.display();    // show the frame
  }
}

// Stop the engine/game loop
void Engine::stop() { isRunning = false; }
