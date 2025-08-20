#pragma once
class Game;
#include <SFML/Graphics.hpp>

class Engine {
public:
    void init();            
    void run(Game& game);   
    void stop();           
        
private:
    bool isRunning;
    sf::RenderWindow window;
};
