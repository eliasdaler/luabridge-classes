#pragma once
#include "Character.h"

class Witch : public Character {
public:
    Witch() {};
    ~Witch() {};
    void interact(Player* player);
private:
};