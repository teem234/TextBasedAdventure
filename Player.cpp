//
// Created by td on 3/9/18.
//

#include "Player.h"



Player::Player() : CombatUnit(100,25){
    this->gold = 15;
    itemList.push_back(new ItemHealth());
    this->name = "Player";
}

int Player::getGold() {
    return this->gold;
}

std::vector<Item*> Player::getItems(){
    return this->itemList;
}

void Player::attack() {

}

void Player::addGold(int amount) {
    gold+=amount;
}

void Player::attack(CombatUnit *enem) {
    std::cout  <<enem->getName() << " taking " << this->getDamage() << " damage." << std::endl;
    enem->takeDamage(this->getDamage());
}
void Player::heavyAttack(CombatUnit* enem){
    int rngMiss = rand() % 10 +1;
    if (rngMiss <4 ) {
        std::cout << " Attack missed!" << std::endl;
    }
    else {
        std::cout  << enem->getName()<< " taking " << this->getDamage()*2 << " damage." << std::endl;
        enem->takeDamage(this->getDamage()*2);
    }
}
void Player::strikeAttackMultiple(std::vector<CombatUnit*> enemies){
    for (auto& enem : enemies){
        std::cout << enem->getName() << " taking " << this->getDamage()*0.7 << " damage." << std::endl;
        enem->takeDamage(this->getDamage()*0.7);
    }
}

bool Player::hasBeatBoss() {
    return this->bossBeat;
}

bool Player::setBeat() {
    this->bossBeat = true;
}