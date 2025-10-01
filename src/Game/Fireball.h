#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>

class Fireball {
public:
    Fireball() = default;
    Fireball(std::filesystem::path filePath, float x, float y, float minY,
               float maxY, float speed);
    
    sf::Texture fireballTexture;
    std::unique_ptr<sf::Sprite> fireballSprite;
    
    void createFireballTexture(std::filesystem::path filePath, float x, float y,
                               float minY, float maxY, float speed);
    void createFireballTexture(std::filesystem::path filePath, float _startX, float _startY, float _xSpeed, float _ySpeed);
    
    // setter functions
    void setFireballBounds(float width, float height);
    void setVerticalFireballBounds(float minY, float maxY);
    void setDiagonalSpeed(float xSpeed, float ySpeed);
    void setSpeed(float speed);

    // game functions
    void update(float deltaTime);
    void draw(sf::RenderWindow &window);
   
private:
    int boundWidth, boundHeight;
    sf::Vector2f diagonalSpeed;
    float speed;
    sf::Vector2f verticalBounds;
    bool movingUp;
};
