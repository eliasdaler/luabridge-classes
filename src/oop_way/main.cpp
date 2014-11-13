#include <iostream> 

#include "Guard.h"
#include "Player.h"
#include "Witch.h"

int main() {
    Player player;
    Witch witch;
    witch.setName("Lucia");
    Guard guard;
    guard.setName("Sam");

    std::cout << "|Player walks around the town and talks with some npcs" << std::endl;
    witch.interact(&player);
    guard.interact(&player);

    std::cout << "|Player goes on a great adventure!" << std::endl;
    std::cout << "|but gets beaten up by some foes..." << std::endl;
    player.setHp(player.getHp() - 5);
    std::cout << "|Back to the town... Let's talk to the witch" << std::endl;
    witch.interact(&player);
}