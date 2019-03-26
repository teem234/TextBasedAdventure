//
// Created by td on 3/9/18.
//

#include "CombatUnit.h"

CombatUnit::CombatUnit(double health, double damage) {
    this->health = health;
    this->baseDamage = damage;
    this->name = name;
}
double CombatUnit::getHealth() {
    return this->health;
}

double CombatUnit::getDamage() {
    return this->baseDamage;
}

std::string CombatUnit::getName(){
    return this->name;
}

void CombatUnit::takeDamage(double amount) {
    health -=amount;
}
void CombatUnit::addHealth(double amount) {
    health+=amount;
}
void CombatUnit::addDamage(double amount) {
    baseDamage+=amount;
}