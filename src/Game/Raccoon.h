#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm> // for std::swap
#include <filesystem>
#include <iostream>
#include <memory>

class Raccoon {
public:
  Raccoon(std::filesystem::path filePath, float x, float y);

  void createRaccoonTexture(std::filesystem::path filePath, float x, float y);
  void draw(sf::RenderWindow &window);
  void update();
  void setBounds(float width, float height);

  sf::Texture raccoonTexture;
  std::unique_ptr<sf::Sprite> raccoonSprite;

private:
  int boundWidth, boundHeight;
};
