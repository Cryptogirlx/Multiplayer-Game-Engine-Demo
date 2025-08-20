#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "./Engine/Engine.h"

class Game {
    public:
    void start();
    void update();
    void render(sf::RenderWindow& window);
   
    private:
    Player player;

};