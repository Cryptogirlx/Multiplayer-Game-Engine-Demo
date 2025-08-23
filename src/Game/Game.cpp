#include "Game.h"
#include <iostream>
#include <memory>

// Constructor with member initializer list
Game::Game() { std::cout << "Game constructor called!" << std::endl; }

void Game::start() {

  // Import font - ADD DEBUGGING
  std::cout << "Attempting to load font..." << std::endl;
  if (!font.openFromFile(
          "../assets/fonts/Roboto/Roboto-VariableFont_wdth,wght.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
    std::cerr << "Current working directory might be wrong" << std::endl;
    // Don't continue if font fails to load
    return;
  }
  std::cout << "Font loaded successfully!" << std::endl;

  // Setup text
  nameText = std::make_unique<sf::Text>(font, sf::String("NameText"), 20);
  nameText->setFillColor(sf::Color::White);
  nameText->setPosition(sf::Vector2f(10.f, 10.f));

  healthText = std::make_unique<sf::Text>(font, sf::String("HealthText"), 20);
  healthText->setFillColor(sf::Color::White);
  healthText->setPosition(sf::Vector2f(10.f, 40.f));

  scoreText = std::make_unique<sf::Text>(font, sf::String("ScoreText"), 100);
  scoreText->setFillColor(sf::Color::White);
  scoreText->setPosition(sf::Vector2f(10.f, 80.f));

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
