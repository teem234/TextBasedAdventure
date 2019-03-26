//
// Created by td on 3/9/18.
//

#ifndef MYGAME_GAMECONTROLLER_H
#define MYGAME_GAMECONTROLLER_H


#include "Player.h"
#include "LevelNode.h"
#include <iostream>
#include <string>
#include "LevelBoss.h"

class GameController {

public:
    void startGame();
    GameController();
    GameController(int x, int y);
    void generateDirections();
    void nextTurn();
    void takeTurn();
    void printMap();
    bool gameOver();

private:
    Player *player;
    int playerx = 0;
    int playery = 0;
    int sizex;  //x y params for map
    int sizey;
    LevelNode ***map;
    std::vector<std::string> validDirections;



};


#endif //MYGAME_GAMECONTROLLER_H
