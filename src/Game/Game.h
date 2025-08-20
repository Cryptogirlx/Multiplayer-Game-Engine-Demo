#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>

class Game {
    public:
    void start();
    void update();
    void render(sf::RenderWindow& window);
   
    private:
    Player player;

};