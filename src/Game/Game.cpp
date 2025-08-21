#include "../Engine/Engine.h"
#include "Game.h"
#include <iostream>
#include "Player.h"

Game::Game() {
    
    std::cout << "Game constructor called!" << std::endl;  // Debug output
}
void Game::start() {
    std::cout << "Game started" << std::endl;
}

void Game::update() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) == true){
            player.move(Player::UP);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::
    A)){ 
            player.move(Player::LEFT);
    }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::
    S)){  
            player.move(Player::DOWN);
    }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::
    D)){  
            player.move(Player::RIGHT);
    }
    std::cout << "Game updated" << std::endl;
}

void Game::render(sf::RenderWindow& window) {

    // draw avatar
    window.draw(player.avatar);
    std::cout << "Game rendered" << std::endl;
}
