#pragma once

#include <string>
#include "Player.h"

class Character {
public:
    Character() {};
    virtual ~Character() {};
    virtual void interact(Player* player) = 0;

    std::string getName() const { return name; }
    void setName(const std::string& name) { this->name = name; }
protected:
    std::string name;
};