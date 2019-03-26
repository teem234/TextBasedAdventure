//
// Created by td on 3/9/18.
//

#include "Item.h"

std::string Item::getName() {
    return this->name;
}

Item::Item(std::string name){
    this->name = name;
}
Item::Item(std::string name, int goldCost){
    this->goldCost = goldCost;
    this->name = name;
}
int Item::getCost(){
    return this->goldCost;
}