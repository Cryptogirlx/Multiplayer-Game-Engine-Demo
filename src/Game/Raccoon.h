#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>

class Raccoon {
public:
  Raccoon() = default;
  Raccoon(std::filesystem::path filePath, float x, float y);

  sf::Texture raccoonTexture;
  std::unique_ptr<sf::Sprite> raccoonSprite;
  bool isCollected = false;

  void setBounds(float width, float height);
  void createRaccoonTexture(std::filesystem::path filePath, float x, float y);
  void draw(sf::RenderWindow &window);
  void update(float deltaTime);

private:
  int boundWidth, boundHeight;
};
