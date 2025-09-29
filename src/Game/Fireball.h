#include "Fireball.h"
#include <algorithm> // for std::swap
#include <filesystem>
#include <iostream>
#include <memory>

class Fireball {
    public:
    Fireball() = default;
    Fireball(std::filesystem::path filePath, float x, float y, float minY,
               float maxY);
    
      sf::Texture meteoriteTexture;
      std::unique_ptr<sf::Sprite> meteoriteSprite;
      
      void createFireballTexture(std::filesystem::path filePath, float x, float y,
                                 float minY, float maxY, float speed);
      
      // setter functions
      void setFireballBounds(float width, float height);
      void setVerticalFireballBounds(float minY, float maxY);
      void setSpeed(float speed);
      sf::Vector2f getVerticalMeteoriteBounds();


      // game functions
      void update();
      void draw(sf::RenderWindow &window);
     
    
    private:
      int boundWidth, boundHeight;
      float speed;
      sf::Vector2f verticalBounds;
    };