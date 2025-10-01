#include "Fireball.h"
#include <algorithm> // for std::swap
#include <filesystem>
#include <iostream>
#include <memory>

Fireball::Fireball(std::filesystem::path filePath, float x, float y, float minY,
    float maxY, float speed) {

// Start the obstacle somewhere inside the vertical range (not exactly at min
// or max)
float startY = minY + (maxY - minY) / 2.0f;
setSpeed(speed);
createObstacleTexture(filePath, x, startY, minY, maxY,speed);

std::cout << "Fireball initialized!" << std::endl;

}

// setter functions
void Fireball::createFireballTexture(std::filesystem::path filePath, float _startX, float _startY,float _xSpeed, float _ySpeed) {

        if (!fireballTexture.loadFromFile(filePath)) {

            std::cerr << "Failed to load fireball texture from: " << filePath
                      << std::endl;
            return;
          }
        
          std::cout << "Fireball texture loaded successfully from: " << filePath
                    << std::endl;
        

          fireballSprite = std::make_unique<sf::Sprite>(fireballTexture);
          fireballSprite->setPosition(sf::Vector2f(_startX, _startY));
    
          setDiagonalSpeed(_xSpeed, _ySpeed);

}


void Fireball::setDiagonalSpeed(float _xSpeed, float _ySpeed ) {
    diagonalSpeed.x = _xSpeed;
    diagonalSpeed.y = _ySpeed;
}

// game functions
void Fireball::draw(sf::RenderWindow &window) {
    if (fireballSprite && fireballTexture.getSize().x > 0) {
      window.draw(*fireballSprite);
    }
  }



