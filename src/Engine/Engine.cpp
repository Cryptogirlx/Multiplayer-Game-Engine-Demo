#include "Engine.h"
#include "../Game/Game.h"

void Engine::init() {
    isRunning = true;
}

void Engine::run(Game& game){
    game.start();
    while (isRunning) {
        game.update();
        game.render();
    }
}
