cmake_minimum_required(VERSION 3.9)
project(TextAdventure)

set(CMAKE_CXX_STANDARD 11)

add_executable(mygame main.cpp Enemy.cpp Enemy.h Item.cpp Item.h LevelNode.cpp LevelNode.h GameController.cpp GameController.h CombatUnit.cpp CombatUnit.h Player.cpp Player.h LevelChest.cpp LevelChest.h LevelFight.cpp LevelFight.h Level.cpp Level.h ItemHealth.cpp ItemHealth.h ItemDamage.cpp ItemDamage.h LevelBoss.cpp LevelBoss.h LevelEmpty.cpp LevelEmpty.h LevelShop.cpp LevelShop.h)
