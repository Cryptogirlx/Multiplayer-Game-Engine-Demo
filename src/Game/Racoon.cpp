#include "Raccoon.h"
#include <algorithm> // for std::swap
#include <filesystem>
#include <iostream>
#include <memory>

Raccoon::Raccoon(std::filesystem::path filePath, float x, float y) {
  createRaccoonTexture(filePath, x, y);
}

void Raccoon::createRaccoonTexture(std::filesystem::path filePath, float x,
                                 float y) {
  // Load reward texture
  if (!raccoonTexture.loadFromFile(filePath)) {
    std::cerr << "Failed to load raccoon texture from: " << filePath
              << std::endl;
    return;
  }

  std::cout << "Raccoon texture loaded successfully from: " << filePath
            << std::endl;

  // Create sprite with texture
  raccoonSprite = std::make_unique<sf::Sprite>(raccoonTexture);
  raccoonSprite->setPosition(sf::Vector2f(x, y));
  raccoonSprite->setScale(sf::Vector2f(0.1f, 0.1f));
}

void Raccoon::draw(sf::RenderWindow &window) {
  if (raccoonSprite && raccoonTexture.getSize().x > 0) {
    window.draw(*raccoonSprite);
  }
}

void Raccoon::setBounds(float width, float height) {
  boundWidth = width;
  boundHeight = height;
}

void Raccoon::update() {
  // Add any raccoon-specific update logic here
  // For now, this is just a placeholder
}