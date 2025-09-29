#include "Obstacle.h"
#include <algorithm> // for std::swap
#include <filesystem>
#include <iostream>
#include <memory>

Obstacle::Obstacle(std::filesystem::path filePath, float x, float y, float minY,
                   float maxY) {
  speed = 5.0f;    // movement speed
  movingUp = true; // initial direction

  // Start the obstacle somewhere inside the vertical range (not exactly at min
  // or max)
  float startY = minY + (maxY - minY) / 2.0f;

  createObstacleTexture(filePath, x, startY, minY, maxY);
  std::cout << "Obstacle initialized!" << std::endl;
}

void Obstacle::setBounds(float width, float height) {
  boundWidth = width;
  boundHeight = height;
}

void Obstacle::createObstacleTexture(std::filesystem::path filePath, float x,
                                     float y, float minY, float maxY) {
  // Load obstacle texture
  if (!obstacleTexture.loadFromFile(filePath)) {
    std::cerr << "Failed to load obstacle texture from: " << filePath
              << std::endl;
    return;
  }

  std::cout << "Obstacle texture loaded successfully from: " << filePath
            << std::endl;

  // Create sprite with texture
  obstacleSprite = std::make_unique<sf::Sprite>(obstacleTexture);
  obstacleSprite->setPosition(sf::Vector2f(x, y));

  // Set vertical bounds
  setVerticalBounds(minY, maxY);
}

void Obstacle::draw(sf::RenderWindow &window) {
  if (obstacleSprite && obstacleTexture.getSize().x > 0) {
    window.draw(*obstacleSprite);
  }
}

void Obstacle::setVerticalBounds(float _minY, float _maxY) {
  if (_minY > _maxY)
    std::swap(_minY, _maxY);
  verticalBounds.x = _minY; // minY
  verticalBounds.y = _maxY; // maxY
}

sf::Vector2f Obstacle::getVerticalBounds() { return verticalBounds; }

void Obstacle::update() {
  if (!obstacleSprite)
    return; // safety check

  // Current position
  sf::Vector2f pos = obstacleSprite->getPosition();
  float currentX = pos.x;
  float currentY = pos.y;

  // Move vertically between minY (verticalBounds.x) and maxY (verticalBounds.y)
  const float minY = verticalBounds.x;
  const float maxY = verticalBounds.y;

  if (movingUp) {
    currentY -= speed;
    if (currentY <= minY) {
      currentY = minY;
      movingUp = false;
    }
  } else {
    currentY += speed;
    if (currentY >= maxY) {
      currentY = maxY;
      movingUp = true;
    }
  }

  // Update sprite position
  obstacleSprite->setPosition(sf::Vector2f(currentX, currentY));
}
