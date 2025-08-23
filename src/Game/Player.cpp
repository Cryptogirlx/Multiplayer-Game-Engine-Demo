#include "Player.h"
#include <iostream>

Player::Player() : avatar() {

  x = 250; // Start in playable area (right of text area)
  y = 100;
  health = 100;
  score = 0;
  speed = 4;
  name = "Player"; // Add this line to initialize the name

  boundWidth = 800;
  boundHeight = 600;

  avatar.setSize(sf::Vector2f(50.f, 50.f));
  avatar.setFillColor(sf::Color::Red);

  avatar.setPosition(
      sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
}

void Player::setBounds(float width, float height) {
  boundWidth = width;
  boundHeight = height;
}

void Player::draw(sf::RenderWindow &window) { window.draw(avatar); }

void Player::move(Direction direction) {
  switch (direction) {
  case UP:
    y -= speed;
    break;
  case DOWN:
    y += speed;
    break;
  case LEFT:
    x -= speed;
    break;
  case RIGHT:
    x += speed;
    break;
  }

  // clamp: keep inside bounds and avoid text area
  // Text area is roughly from x=0 to x=200, y=0 to y=120
  if (x < 200) // Don't go into text area on left
    x = 200;
  if (y < 0)
    y = 0;
  if (x > boundWidth - avatar.getSize().x)
    x = boundWidth - avatar.getSize().x;
  if (y > boundHeight - avatar.getSize().y)
    y = boundHeight - avatar.getSize().y;

  // Update avatar position
  avatar.setPosition(
      sf::Vector2f(static_cast<float>(x), static_cast<float>(y)));
}

sf::String Player::getPlayerName() { return name; }