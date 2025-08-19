#include "Player.h"

void Player::move(Direction direction) {
    switch (direction) {
        case UP:
            y--;
            std::cout << "Player moved up" << std::endl;
            break;
        case DOWN:
            y++;
            std::cout << "Player moved down" << std::endl;
            break;
        case LEFT:
        x--;
        std::cout << "Player moved left" << std::endl;
        break;
        case RIGHT:
        x++;
        std::cout << "Player moved right" << std::endl;
        break;
    }
}