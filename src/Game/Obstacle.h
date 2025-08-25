#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>

class Obstacle {
public:
  Obstacle() = default;
  Obstacle(std::filesystem::path filePath, int x, int y);

  sf::Texture obstacleTexture;
  std::unique_ptr<sf::Sprite> obstacleSprite;

  void setBounds(float width, float height);
  void createObstacleTexture(std::filesystem::path filePath, int x, int y);
  void draw(sf::RenderWindow &window);

private:
  int boundWidth, boundHeight;
  int speed;
  bool movingUp;
};