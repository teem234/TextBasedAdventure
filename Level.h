//
// Created by td on 3/18/18.
//

#ifndef MYGAME_LEVEL_H
#define MYGAME_LEVEL_H


#include "Player.h"

class Level {
public:
    char getMapSymbol();
    Level(char symbol);
    virtual void startEvent(Player *player)=0;
    bool isCompleted();
private:
    char mapSymbol;
    bool completed = false;
protected:
    void setCompleted();
};


#endif //MYGAME_LEVEL_H
