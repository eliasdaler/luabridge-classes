#include "Player.h"
#include <iostream>

Player::Player() {
    maxHp = 10;
    hp = maxHp;
}

void Player::setHp(int hp) {
    this->hp = hp;
    std::cout << "> Player: " << hp << " HP" << std::endl;
}