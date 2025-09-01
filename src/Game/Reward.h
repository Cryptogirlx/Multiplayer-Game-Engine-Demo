#include "Obstacle.h"
#include <algorithm> // for std::swap
#include <filesystem>
#include <iostream>
#include <memory>

class Reward {
public:
  Reward(std::filesystem::path filePath, float x, float y, float minY,
         float maxY);

  void createRewardTexture(std::filesystem::path filePath, float x, float y,
                           float minY, float maxY);
  void draw(sf::RenderWindow &window);
  void setBounds(float width, float height);

  void update();
  sf::Vector2f getVerticalBounds();

  sf::Texture rewardTexture;
  std::unique_ptr<sf::Sprite> rewardSprite;

private:
  int boundWidth, boundHeight;
  float speed;
  bool movingUp;
  sf::Vector2f verticalBounds;
};
