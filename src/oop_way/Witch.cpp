#include "Witch.h"
#include <iostream>

void Witch::interact(Player* player) {
    if (player->getHp() == player->getMaxHp()) {
        std::cout << name << ": Hi! Come back when you're wounded." << std::endl;
    } else {
        std::cout << name << ": Hi! Let me heal you." << std::endl;
        player->setHp(player->getMaxHp());
    }
}