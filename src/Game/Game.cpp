#include "Game.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include <memory>

// Constructor with member initializer list
Game::Game() { std::cout << "Game constructor called!" << std::endl; }

void Game::start(sf::RenderWindow &window) {

  // Import font - ADD DEBUGGING
  std::cout << "Attempting to load font..." << std::endl;
  if (!font.openFromFile("../assets/fonts/Conthrax-SemiBold.otf")) {
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

  scoreText = std::make_unique<sf::Text>(font, sf::String("ScoreText"), 20);
  scoreText->setFillColor(sf::Color::White);
  scoreText->setPosition(sf::Vector2f(10.f, 80.f));

  // set initial values of texts
  nameText->setString(" Name: " + player.getPlayerName());
  healthText->setString(" Health: " + std::to_string(player.health));
  scoreText->setString("Score: " + std::to_string(player.score));

  // set game background
  if (!backgroundTexture.loadFromFile("../assets/landing.png")) {
    std::cerr << "Failed to load background!" << std::endl;
    std::cerr << "Current working directory might be wrong" << std::endl;
    // Don't continue if font fails to load
    return;
  }
  std::cout << "Background loaded successfully!" << std::endl;

  // Set the texture on the sprite AFTER loading
  backgroundSprite = std::make_unique<sf::Sprite>(backgroundTexture);
  backgroundSprite->setTexture(backgroundTexture);
  backgroundSprite->setPosition(sf::Vector2f(0.f, 0.f));

  // compute background scale

  sf::Vector2u windowSize = window.getSize();
  sf::Vector2u textureSize = backgroundTexture.getSize();

  float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
  float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

  // Apply scaling to the sprite
  backgroundSprite->setScale(sf::Vector2f(scaleX, scaleY));

  std::cout << "Game started" << std::endl;

  // Create obstacles
  obstacles.emplace_back("../assets/Alien1.png", 650, 600);
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

  // Check if texture is loaded before drawing
  if (backgroundTexture.getSize().x > 0 && backgroundTexture.getSize().y > 0) {
    window.draw(*backgroundSprite);
    std::cout << "Drawing background sprite" << std::endl;
  } else {
    std::cout << "Background texture not loaded, skipping draw" << std::endl;
  }

  for (auto &obstacle : obstacles) {
    obstacle.draw(window);
  }

  player.draw(window);
  window.draw(*nameText);
  window.draw(*healthText);
  window.draw(*scoreText);

  std::cout << "Game rendered" << std::endl;
}
