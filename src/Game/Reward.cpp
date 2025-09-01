#include "Reward.h"
#include <algorithm> // for std::swap
#include <filesystem>
#include <iostream>
#include <memory>

void Reward::Reward(std::filesystem::path filePath, float x, float y,
                    float minY, float maxY) {
  speed = 4.0f;    // movement speed
  movingUp = true; // initial direction
}

void Reward::createRewardTexture(std::filesystem::path filePath, float x,
                                 float y, float minY, float maxY) {
  // Load reward texture
  if (!rewardTexture.loadFromFile(filePath)) {
    std::cerr << "Failed to load reward texture from: " << filePath
              << std::endl;
    return;
  }

  std::cout << "Reward texture loaded successfully from: " << filePath
            << std::endl;

  // Create sprite with texture
  rewardSprite = std::make_unique<sf::Sprite>(rewardTexture);
  rewardSprite->setPosition(sf::Vector2f(x, y));

  // Set vertical bounds
  setVerticalBounds(minY, maxY);
}