#include "Player.h"
#include <iostream>
#include <memory>

Player::Player() {
  x = 10; // Start in playable area (right of text area)
  y = 550;
  health = 100;
  score = 0;
  speed = 4;
  name = "Zsofie"; // Add this line to initialize the name

  boundWidth = 800;
  boundHeight = 600;
  startPosition = (sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));

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
  avatarSprite->setPosition(sf::Vector2f(startPosition));

  setVerticalBounds(550, 350);
}

void Player::setBounds(float width, float height) {
  boundWidth = width;
  boundHeight = height;
}
void Player::setVerticalBounds(float _minY, float _maxY) {
  if (_minY > _maxY)
    std::swap(_minY, _maxY);
  verticalBounds.x = _minY; // minY
  verticalBounds.y = _maxY; // maxY
}

sf::Vector2f Player::getVerticalBounds() { return verticalBounds; }
sf::Vector2f Player::getStartPosition() { return startPosition; }

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

  // clamp: keep inside bounds
  verticalBounds = getVerticalBounds();
  if (y < verticalBounds.x) {
    y = verticalBounds.x;
  }

  if (y > verticalBounds.y) {
    y = verticalBounds.y;
  }

  // Update avatar position
  if (avatarSprite) {
    avatarSprite->setPosition(
        sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
  }
}

sf::String Player::getPlayerName() { return name; }

void Player::setPlayerName(std::string playerName) {
  name = playerName;
}

int Player::getPlayerHealth() {
  return health;
}

int Player::getPlayerScore() {
  return score;
}

void Player::updatePlayerHeath() {
  // This method name has a typo (Heath instead of Health)
  // You might want to fix the header file too
}

void Player::updatePlayerScore() {
  // Implementation for updating player score
}