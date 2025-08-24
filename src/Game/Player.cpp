#include "Player.h"
#include <iostream>
#include <memory>

Player::Player() {
  x = 250; // Start in playable area (right of text area)
  y = 100;
  health = 100;
  score = 0;
  speed = 4;
  name = "Player"; // Add this line to initialize the name

  boundWidth = 800;
  boundHeight = 600;

  // Load avatar texture
  if (!avatarTexture.loadFromFile("../assets/avatar.png")) {
    std::cerr << "Failed to load avatar!" << std::endl;
    std::cerr << "Current working directory might be wrong" << std::endl;
    // Don't continue if avatar fails to load
    return;
  }
  std::cout << "Avatar loaded successfully!" << std::endl;

  // Create sprite and set texture
  avatarSprite = std::make_unique<sf::Sprite>(avatarTexture);
  avatarSprite->setTexture(avatarTexture);
  avatarSprite->setPosition(
      sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
}

void Player::setBounds(float width, float height) {
  boundWidth = width;
  boundHeight = height;
}

void Player::draw(sf::RenderWindow &window) {
  if (avatarSprite) {
    window.draw(*avatarSprite);
  }
}

void Player::move(Direction direction) {
  switch (direction) {
  case UP:
    y -= speed;
    break;
  case DOWN:
    y += speed;
    break;
  case LEFT:
    x -= speed;
    break;
  case RIGHT:
    x += speed;
    break;
  }

  // clamp: keep inside bounds and avoid text area
  // Text area is roughly from x=0 to x=200, y=0 to y=120
  if (x < 200) // Don't go into text area on left
    x = 200;
  if (y < 0)
    y = 0;
  if (x > boundWidth - 50) // Assuming sprite width is 50
    x = boundWidth - 50;
  if (y > boundHeight - 50) // Assuming sprite height is 50
    y = boundHeight - 50;

  // Update avatar position
  if (avatarSprite) {
    avatarSprite->setPosition(
        sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
  }
}

sf::String Player::getPlayerName() { return name; }