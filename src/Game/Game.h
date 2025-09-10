#pragma once
#include "../Engine/Engine.h"
#include "Obstacle.h"
#include "Player.h"
#include "Raccoon.h"
#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  void start(sf::RenderWindow &window);
  void update();
  void render(sf::RenderWindow &window);
  void checkCollision();

  sf::Font font;

  std::unique_ptr<sf::Text> nameText;
  std::unique_ptr<sf::Text> healthText;
  std::unique_ptr<sf::Text> scoreText;

  sf::Texture backgroundTexture;
  std::unique_ptr<sf::Sprite> backgroundSprite;

private:
  Player player;
  Obstacle obstacle;
  Raccoon raccoon;
  std::vector<Raccoon> raccoons;
  std::vector<Obstacle> obstacles;
  bool isCollided;
  bool isRunning;
};