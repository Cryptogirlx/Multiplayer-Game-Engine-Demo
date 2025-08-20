#include "Player.h"

Player::Player() {
    x = 100;
    y = 100;
    health = 100;
    score = 0;

    avatar.setSize(sf::Vector2f(50.f, 50.f));   // size of the rectangle
    avatar.setFillColor(sf::Color::Green);      // color
    avatar.setPosition(static_cast<float>(x), static_cast<float>(y)); // initial position
}

void Player::move(Direction direction) {
    switch (direction) {
        case UP:    y -= 5; break;
        case DOWN:  y += 5; break;
        case LEFT:  x -= 5; break;
        case RIGHT: x += 5; break;
    }
    // Update avatar position
    avatar.setPosition(static_cast<float>(x), static_cast<float>(y));
}
