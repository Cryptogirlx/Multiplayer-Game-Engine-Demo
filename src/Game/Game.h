#pragma once
#include "../Engine/Engine.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  void start();
  void update();
  void render(sf::RenderWindow &window);

  sf::Font font;

  std::unique_ptr<sf::Text> nameText;
  std::unique_ptr<sf::Text> healthText;
  std::unique_ptr<sf::Text> scoreText;

  sf::Texture backgroundTexture;
  std::unique_ptr<sf::Sprite> backgroundSprite;

private:
  Player player;
};