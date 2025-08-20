#include "../Engine/Engine.h"
#include "Game.h"
#include <iostream>

void Game::start() {
    std::cout << "Game started" << std::endl;
}

void Game::update() {
    std::cout << "Game updated" << std::endl;
}

void Game::render(sf::RenderWindow& window) {
    std::cout << "Game rendered" << std::endl;
}
