#include "Player.h"

void Player::move(Direction direction) {
    switch (direction) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
    }
}