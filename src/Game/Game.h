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
  void checkObstacleCollision();
  void checkRaccoonCollision();
  sf::Font font;

  std::unique_ptr<sf::Text> nameText;
  std::unique_ptr<sf::Text> healthText;
  std::unique_ptr<sf::Text> scoreText;

  sf::Texture backgroundTexture;
  sf::Texture startingBackgroundTexture;
  std::unique_ptr<sf::Sprite> startingBackgroundSprite;
  std::unique_ptr<sf::Sprite> backgroundSprite;

  enum GameState { StartScreen, Playing, GameOver };
  int currentState;

private:
  Player player;
  Obstacle obstacle;
  Raccoon raccoon;
  std::vector<Raccoon> raccoons;
  std::vector<Obstacle> obstacles;
  bool isCollided;
  bool isRunning;
};