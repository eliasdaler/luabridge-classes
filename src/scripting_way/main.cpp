#include <iostream> 

#include "Player.h"

#include <LuaBridge.h>
extern "C" {
# include "lua.h"
# include "lauxlib.h"
# include "lualib.h"
}

using namespace luabridge;


int main() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    getGlobalNamespace(L)
        .beginClass<Character>("Character")
        .addConstructor<void(*)(void)>()
        .addProperty("name", &Character::getName, &Character::setName)
        .addFunction("say", &Character::say)
        .endClass()
        .deriveClass<Player, Character>("Player")
        .addProperty("hp", &Player::getHp, &Player::setHp)
        .addProperty("maxHp", &Player::getMaxHp, &Player::setMaxHp)
        .endClass();

    Player player;
    player.setName("Player");
    Character witch;
    witch.loadScript(L, "witch.lua", "witch");
    Character guard;
    guard.loadScript(L, "guard.lua", "guard");


    std::cout << "|Player walks around the town and talks with some npcs" << std::endl;
    witch.interact(&player);
    guard.interact(&player);

    std::cout << "|Player goes on a great adventure!" << std::endl;
    std::cout << "|but gets beaten up by some foes..." << std::endl;
    player.setHp(player.getHp() - 5);
    std::cout << "|Back to the town... Let's talk to the witch" << std::endl;
    witch.interact(&player);
}