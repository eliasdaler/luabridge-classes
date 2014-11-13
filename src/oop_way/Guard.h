#pragma once
#include "Character.h"

class Guard : public Character {
public:
    Guard() {};
    ~Guard() {};
    void interact(Player* player);
private:
};