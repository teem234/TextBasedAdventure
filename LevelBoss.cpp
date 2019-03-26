//
// Created by td on 3/19/18.
//

#include "LevelBoss.h"

LevelBoss::LevelBoss() : Level('B') {

    enemAmount = 1;
    std::string names[] = {"GIANT WORM WTF WOW", "CUBONES MOM WITH BONES", "RAT WITH 7 HEADS", "CUBONES MOM's MOM", "Shaggy(from scooby doo ok)", "Shaggy(The rapper) AHHHH"};
    int rng = rand() % 6;
    enemies.push_back(new Enemy(rand() % 250+80,rand() % 45 + 20,names[rng]));
}

    void LevelBoss::startEvent(Player *player) {

        std::cout << "Encountered BOSS BATTLE. ITS " << enemies[0]->getName() << " OMG" << std::endl;

        while (player->getHealth() > 0 && enemAmount > 0 && !this->isCompleted()) {
            std::cout << "Player Health : " << player->getHealth() << std::endl;
            for (auto &en : enemies) {
                std::cout << en->getName() << " Health: " << en->getHealth() << ", ";
            }
            std::cout << std::endl;
            playerOptions(player);
            if (this->isCompleted()) break;
            enemyAttack(player);
        }
        this->setCompleted();
    }

    void LevelBoss::enemyAttack(Player *player) {
        for (auto &ene : enemies) {
            int rng = rand() % 9;

            if (rng < 7) {
                ene->attack(player);
            } else {
                std::cout << ene->getName() << " Missed!" << std::endl;
            }

        }
    }

    void LevelBoss::playerOptions(Player *player) {
        std::string topOptions[] = {"Attack", "Item", "Run"};
        std::string attackOptions[] = {"Bash", "Strike", "Heavy"};

        std::string option;
        bool found = false;

        while (!found) {
            std::cout << "Actions: Attack, Item, Run" << std::endl;
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

        if (option == "Attack") {
            found = false;
            while (!found) {
                std::cout << "Attack Actions: Bash, Strike, Heavy" << std::endl;
                std::getline(std::cin, option);
                for (auto &str : attackOptions) {
                    if (option == str) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Enter valid option" << std::endl;
                }
            }
            //if (enemAmount == 1) {
            //use that attack on them
            // }
            //else {
            //pick target
            std::cout << "Which enemy to attack? ";
            for (int i = 1; i <= enemAmount; i++) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
            std::string attackChoice;

            found = false;
            while (!found) {

                std::getline(std::cin, attackChoice);
                for (int i = 1; i <= enemAmount; i++) {
                    if (attackChoice == std::to_string(i)) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Enter valid option" << std::endl;
                }

            }
            int attackindex = std::stoi(attackChoice);
            if (option == "Bash") {
                player->attack(enemies[attackindex - 1]);
            } else if (option == "Heavy") {
                player->heavyAttack(enemies[attackindex - 1]);
            } else if (option == "Strike") {
                player->strikeAttackMultiple(enemies);
            }


        } else if (option == "Item") {
            found = false;
            int itemCount = player->getItems().size();
            if (itemCount > 0) {
                std::cout << "Which item?:" << std::endl;
                int i = 1;
                for (auto &item : player->getItems()) {
                    std::cout << i << ": " << item->getName() << std::endl;
                    i++;
                }
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

                int potionindex = std::stoi(option);
                player->getItems()[potionindex - 1]->useItem(player);


                player->itemList.erase(player->itemList.begin() + potionindex - 1);


            } else {
                std::cout << "No items!" << std::endl;
            }

        } else if (option == "Run") {

            std::cout << "Can't Escape!" << std::endl;
        }





        for (auto &enem : enemies) {
            if (enem->getHealth() <= 0) {
                std::cout << enem->getName() << " fainted!!!!AAHHHH." << std::endl;
                this->setCompleted();
                player->setBeat();
                enemAmount -= 1;
            }


    }
}