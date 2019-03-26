//
// Created by td on 3/19/18.
//

#include "LevelShop.h"
#include "ItemDamage.h"


LevelShop::LevelShop() : Level('S'){

    healthrng = rand() % 11+4;
    dmgrng = rand() % 15 + 5;
    inventory.push_back(new ItemHealth(healthrng));
    inventory.push_back(new ItemDamage(dmgrng));
    itemCount = 2;

}

void LevelShop::startEvent(Player *player) {
    std::cout<< "Potion Seller: MY POOOTIONS ARE TOO STRONG FOR YOU TRAVELER" << std::endl;
    std::cout << "Goods for sale: " << std::endl;
    bool found=false;
    std::string option;

    int itemCount = inventory.size();
    if (itemCount >0) {

        int i = 1;
        for (auto &item : inventory) {
            std::cout << i << ": " << item->getName() << " " << item->getCost() << " gold." << std::endl;
            i++;
        }

        std::cout << "Would you like to purchase one of my stroooong potions? (yes/no)" << std::endl;
        std::string topOptions[] = {"yes", "no"};


        while (!found) {

            std::getline(std::cin, option);
            for (auto &str : topOptions) {
                if (option == str) {
                    found = true;
                    break;
                }
            }//could use std find but being annoying
            if (!found) {
                std::cout << "Enter valid option" << std::endl;
            }
        }
        if (option == "yes") {

            found = false;
            std::cout << "Which would you like to purchase? Enter the number" << std::endl;

            std::getline(std::cin, option);
            for (int i = 1; i <= itemCount; i++) {
                if (option == std::to_string(i)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Enter valid option" << std::endl;
            }
            int choice = std::stoi(option);
            choice -= 1;
            if (player->getGold() >= inventory[choice]->getCost()) {
                player->itemList.push_back(inventory[choice]);
                player->addGold(-inventory[choice]->getCost());
                inventory.erase(inventory.begin() + choice);
                std::cout << "Purchased " << inventory[choice]->getName() << std::endl;
                if (inventory.size() == 0) {
                    std::cout << "Sold out, farewell traveler" << std::endl;
                    setCompleted();
                }

            } else std::cout << "They are too strong. You can't afford. Farewell" << std::endl;
        }
        else {
            std::cout<< "You are far too weak for them anyway, Goodbye" << std::endl;
        }
    }









    }
