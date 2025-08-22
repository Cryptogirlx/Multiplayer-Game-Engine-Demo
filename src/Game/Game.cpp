#include "Game.h"
#include <iostream>

// Constructor with member initializer list
Game::Game() { std::cout << "Game constructor called!" << std::endl; }

void Game::start() {

  // Import font
  if (!font.openFromFile("assets/fonts/Conthrax-SemiBold.otf")) {
    std::cerr << "Failed to load font!" << std::endl;
  }

  // create object from pointer
  nameText = std::make_unique<sf::Text>("PlayerName", font, 20);
  healthText = std::make_unique<sf::Text>("PlayerHealth", font, 20);
  scoreText = std::make_unique<sf::Text>("PlayerScore", font, 20);

  // Setup text
  nameText->setFillColor(sf::Color::White);
  nameText->setPosition(sf::Vector2f(10.f, 10.f));

  healthText->setFillColor(sf::Color::White);
  healthText->setPosition(sf::Vector2f(10.f, 40.f));

  scoreText->setFillColor(sf::Color::White);
  scoreText->setPosition(sf::Vector2f(10.f, 70.f));

  // set initial values of texts

  nameText->setString(" Name: " + player.getPlayerName());
  healthText->setString(" Health: " + std::to_string(player.health));
  scoreText->setString("Score: " + std::to_string(player.score));

  std::cout << "Game started" << std::endl;
}

void Game::update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
    player.move(Player::UP);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    player.move(Player::LEFT);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    player.move(Player::DOWN);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    player.move(Player::RIGHT);
  }

  // Update text each frame (in case health/score changes)
  healthText->setString(" Health: " + std::to_string(player.health));
  scoreText->setString(" Score: " + std::to_string(player.score));

  std::cout << "Game updated" << std::endl;
}

void Game::render(sf::RenderWindow &window) {
  player.draw(window); // draw avatar

  // draw UI
  window.draw(*nameText);
  window.draw(*healthText);
  window.draw(*scoreText);
  std::cout << "Game rendered" << std::endl;
}
