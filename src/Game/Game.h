#pragma once
#include "../Engine/Engine.h"
#include "Obstacle.h"
#include "Player.h"
#include "Raccoon.h"
#include "Fireball.h"
#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  void start(sf::RenderWindow &window);
  void update(float deltaTime);
  void render(sf::RenderWindow &window);
  void checkObstacleCollision();
  void checkRaccoonCollision();
  void handleEvent(const sf::Event& event);
  sf::Font font;

  std::unique_ptr<sf::Text> nameText;
  std::unique_ptr<sf::Text> healthText;
  std::unique_ptr<sf::Text> scoreText;

  sf::Texture backgroundTexture;
  sf::Texture startingBackgroundTexture;
  std::unique_ptr<sf::Sprite> startingBackgroundSprite;
  std::unique_ptr<sf::Sprite> backgroundSprite;

  std::unique_ptr<sf::Text> titleText;
  std::unique_ptr<sf::Text> inputPromptText;
  std::unique_ptr<sf::Text> playerNameText;
  std::unique_ptr<sf::Text> startButtonText;

  // input handling
  std::string playerNameInput;
  bool isTyping;

  enum GameState { StartScreen, Playing, GameOver };
  int currentState;

private:
  Player player;
  Obstacle obstacle;
  Raccoon raccoon;
  Fireball fireball;
  std::vector<Raccoon> raccoons;
  std::vector<Obstacle> obstacles;
  std::vector<Fireball> fireballs;
  bool isCollided;
  bool isRunning;
};