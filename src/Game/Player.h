#pragma once
#include <SFML/Graphics.hpp> 

class Player {
    public:
    Player();

    int health;
    int score;
  
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    void move(Direction direction);
    void setBounds(float width, float height);
    void draw(sf::RenderWindow& window);
 
    sf::Sprite avatar;

    private:
    int x, y;
    int speed;
    int boundWidth, boundHeight; 
};                  