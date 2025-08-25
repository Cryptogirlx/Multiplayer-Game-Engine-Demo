#include "Obstacle.h"
#include <filesystem>
#include <iostream>
#include <memory>

Obstacle::Obstacle(std::filesystem::path filePath, int x, int y) {
  createObstacleTexture(filePath, x, y);
  std::cout << "Obstacle initialized!" << std::endl;
}

void Obstacle::setBounds(float width, float height) {
  boundWidth = width;
  boundHeight = height;
}

void Obstacle::createObstacleTexture(std::filesystem::path filePath, int x,
                                     int y) {

  // Load obstacle texture
  if (!obstacleTexture.loadFromFile(filePath)) {
    std::cerr << "Failed to load obstacle texture from: " << filePath
              << std::endl;
    std::cerr << "Current working directory might be wrong" << std::endl;
    return;
  }

  std::cout << "Obstacle texture loaded successfully from: " << filePath
            << std::endl;

  // Create sprite with texture
  obstacleSprite = std::make_unique<sf::Sprite>(obstacleTexture);
  obstacleSprite->setPosition(
      sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
}

void Obstacle::draw(sf::RenderWindow &window) {
  if (obstacleSprite && obstacleTexture.getSize().x > 0) {
    window.draw(*obstacleSprite);
    std::cout << "Drawing obstacle sprite" << std::endl;
  } else {
    std::cout << "Cannot draw obstacle - sprite or texture missing"
              << std::endl;
  }
}