#include "Character.h"
#include <iostream>

Character::Character() : interactFunc(nullptr) {
}

Character::~Character() {
}

void Character::loadScript(luabridge::lua_State* L, const std::string& scriptFilename, const std::string& tableName) {
    using namespace luabridge;
    if (luaL_dofile(L, scriptFilename.c_str()) == 0) {
        LuaRef table = getGlobal(L, tableName.c_str());
        if (table.isTable()) {
            name = table["name"].cast<std::string>();
            if (table["name"].isString()) {
                name = table["name"].cast<std::string>();
            } else {
                name = "Null";
            }

            if (table["interact"].isFunction()) {
                interactFunc = std::make_shared<LuaRef>(table["interact"]);
            } else {
                interactFunc.reset();
            }
        }
    } else {
       std::cout << "Error, can't open script!" << std::endl;
    }
}

void Character::say(const std::string& text) {
    std::cout << name << ": " << text << std::endl;
}

void Character::interact(Player* player) {
    if (interactFunc) {
        try{
            (*interactFunc)(this, player);
        }
        catch (luabridge::LuaException const& e) {
            std::cout << "LuaException: " << e.what() << std::endl;
        }
    }
}