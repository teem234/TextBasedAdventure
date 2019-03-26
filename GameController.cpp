//
// Created by td on 3/9/18.
//


#include "GameController.h"



GameController::GameController() {
    player = new Player();
    sizex = 6;
    sizey = 6;
    //Define Entire game Map Size
    srand(time(NULL));
    map = new LevelNode**[sizex];
    for (int i = 0; i < sizex; i++){
        map[i] = new LevelNode*[sizey];

        for (int j = 0; j < sizey; j++){
            map[i][j] = new LevelNode();
        }
    }
    std::cout << "You arrive in a strange world...filled with many different creatures. Can you survive, do you want to?" << std::endl;
} //generate array map

GameController::GameController(int x, int y) {
    player = new Player();
    sizex = x;
    sizey = y;
    srand(time(NULL));
    map = new LevelNode**[sizex];
    for (int i = 0; i < sizex; i++){
        map[i] = new LevelNode*[sizey];

        for (int j = 0; j < sizey; j++){
            if ( i == 0 && j == 0){
                Level *temp = new LevelEmpty();
                map[i][j] = new LevelNode(temp);
            }
            else if (i == sizex-1 && j==sizey-1){
                Level *temp = new LevelBoss();
                map[i][j] = new LevelNode(temp);
            }
            else {
                map[i][j] = new LevelNode();
            }
        }
    }
    std::cout << "You arrive in a strange world...filled with many different creatures. Can you survive, do you want to?" << std::endl;
} //generate array map

bool GameController::gameOver() {
    if (player->getHealth() <=0){
        std::cout << "You died! GAME OVER" << std::endl;
        return true;
    }
    else if (player->hasBeatBoss()){
        std::cout << "Congratulations!! YOU WIN. You've unlocked....nothing" << std::endl;
        return true;
    }
    else return false;
}

void GameController::takeTurn() {
    std::cout << "Stats ---Health: " << player->getHealth() << " ---Gold: " << player->getGold() << " ---Damage: " << player->getDamage() << std::endl;
    std::cout << "You are currently at " << playery << " , " << playerx << std::endl << "Choose your path" << std::endl;
    generateDirections();
    for (auto dir : validDirections) {
        std::cout << dir << " ";
    }
    std::cout << std::endl;

    bool validchoice = false;
    std::string playerchoice;

    while (!validchoice) {

        getline(std::cin, playerchoice);

        for (auto dir: validDirections) {
            if (playerchoice == dir) {
                validchoice = true;
                break;
            }
        }
        if (!validchoice) {
            std::cout << "Try again....you can't go that way" << std::endl;
        }
    }

    if (playerchoice == "Up") {
        playerx-=1;
    }
    if (playerchoice == "Down") {
        playerx+=1;
    }
    if (playerchoice == "Left") {
        playery-=1;
    }
    if (playerchoice == "Right") {
        playery +=1;
    }
    if (!map[playerx][playery]->getLevel()->isCompleted()) {


        map[playerx][playery]->getLevel()->startEvent(player);
    }
}

void GameController::generateDirections(){
    validDirections.clear();
    if (playery - 1 >= 0 ){
        validDirections.push_back("Left");
    }
    if (playery + 1 < sizey ){
        validDirections.push_back("Right");
    }
    if (playerx - 1 >= 0 ){
        validDirections.push_back("Up");
    }
    if (playerx + 1 < sizex ){
        validDirections.push_back("Down");
    }

}

void GameController::printMap(){
    for (int i = 0; i < sizex; i ++){
        for (int j = 0; j < sizey; j++){

            if ( i == playerx && j == playery) {
                std::cout << "P ";
            }
                else if( map[i][j]->getLevel()->isCompleted()){
                        std::cout << "X ";
                    }

            else {
                std::cout << map[i][j]->getLevel()->getMapSymbol() << " ";
            }
        }
        std::cout<< std::endl;
    }
}
