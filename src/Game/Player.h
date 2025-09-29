#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
  Player();

  int health;
  int score;

  enum Direction { UP, DOWN, LEFT, RIGHT };
  void move(Direction direction);
  void setBounds(float width, float height);

  void draw(sf::RenderWindow &window);

  void setVerticalBounds(float minY, float maxY);
  sf::Vector2f getVerticalBounds();
  sf::Vector2f getStartPosition();

  void setPlayerName(std::string playerName);
  sf::String getPlayerName();

  int getPlayerHealth();
  int getPlayerScore();

  void updatePlayerHeath();
  void updatePlayerScore();

  sf::Texture avatarTexture;
  std::unique_ptr<sf::Sprite> avatarSprite;

private:
  int x, y;
  int speed;
  int boundWidth, boundHeight;
  sf::String name;
  sf::Vector2f verticalBounds;
  sf::Vector2f startPosition;
};