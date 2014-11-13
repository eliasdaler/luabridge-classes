#pragma once

#include <string>

class Player {
public:
    Player();
    
    int getHp() const { return hp; }
    void setHp(int hp);

    int getMaxHp() const { return maxHp; }
    void setMaxHp(int maxHp) { this->maxHp = maxHp; }
private:
    int hp;
    int maxHp;
};