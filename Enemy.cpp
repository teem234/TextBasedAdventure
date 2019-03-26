//
// Created by td on 3/9/18.
//


#include "Enemy.h"

Enemy::Enemy(): CombatUnit(rand() % 45 + 20, rand() % 20 + 9 ) {

    std::string names[] = {"Skeleton", "Dead Bird", "Sick Puppy", "Zombie", "Fat Zombie", "Dead Cat", "Ghoul", "Headless Rat", "Mothman" };
int namechoice = rand() % 9 ;
this->name=names[namechoice];

}

Enemy::Enemy(int health, int damage, std::string name) : CombatUnit(health,damage){
    this->name = name;
}

void Enemy::attack(){

}



void Enemy::attack(CombatUnit *player) {
    std::cout << this->getName() << " Attacking player for " << this->getDamage() << " damage" <<std::endl;
    player->takeDamage(this->getDamage());
}

void Enemy::heavyAttack(CombatUnit *player) {
    int rng = rand() % 10 + 1;

    if (rng < 7){
        std::cout << this->getName() << " Attacking player for " << this->getDamage()*1.5 << " damage" <<std::endl;
        player->takeDamage(this->getDamage()*1.5);
    }
    else {
        std::cout << this->getName() << " missed!"<< std::endl;
    }

}