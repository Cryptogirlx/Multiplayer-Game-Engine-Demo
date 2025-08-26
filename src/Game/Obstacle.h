#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>

class Obstacle {
public:
  Obstacle() = default;
  Obstacle(std::filesystem::path filePath, float x, float y, float minY,
           float maxY);

  sf::Texture obstacleTexture;
  std::unique_ptr<sf::Sprite> obstacleSprite;

  void setBounds(float width, float height);
  void createObstacleTexture(std::filesystem::path filePath, float x, float y,
                             float minY, float maxY);
  void draw(sf::RenderWindow &window);
  void setVerticalBounds(float minY, float maxY);
  void update();
  sf::Vector2f getVerticalBounds();

private:
  int boundWidth, boundHeight;
  float speed;
  bool movingUp;
  sf::Vector2f verticalBounds;
};