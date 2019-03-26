//
// Created by td on 3/18/18.
//


#include "LevelChest.h"


LevelChest::LevelChest() : Level('C'){

}

void LevelChest::startEvent(Player *player) {
    std::cout << "You have come across a chest in the dungeon and open it" << std::endl;
    srand(time(NULL));

    int rng = rand() %  9 + 1;


    int dmgrng;
    int healthrng;
    int posrng;
    int goldrng;

    switch (rng) {
        case 1:
            healthrng = rand() % 20 + 1;
            posrng = rand() % 2;

            if (posrng == 0) {
                healthrng = -healthrng;
            }

            std::cout << "The chest contains a relic.....Players health is affected " << healthrng <<std::endl;
            player->addHealth(healthrng);
            break;
        case 2:
            goldrng = rand() % 20 + 1;
            posrng = rand() % 2;

            if (posrng == 0) {
                goldrng = -goldrng;
            }

            std::cout << "The chest contains a relic.....Players gold is affected " << goldrng <<std::endl;
            player->addGold(goldrng);
            break;
        case 3:
            dmgrng = rand() % 5 + 1;
            posrng = rand() % 2;

            if (posrng == 0) {
                dmgrng= -dmgrng;
            }

            std::cout << "The chest contains a relic.....Players damage is affected " << dmgrng<< std::endl;
            player->addDamage(dmgrng);
            break;

        case 4:
            healthrng = rand() % 13 + 1;


            std::cout << "The chest contains a trophy.....health stat boost! " << healthrng <<std::endl;
            player->addHealth(healthrng);
            break;
        case 5:
            goldrng = rand() % 25 + 1;


            std::cout << "The chest contains a trophy.....gold stat boost! " << goldrng <<std::endl;
            player->addGold(goldrng);
            break;
        case 6:
            dmgrng = rand() % 7 + 1;

            std::cout << "The chest contains a trophy.....damage stat boost! " << dmgrng<< std::endl;
            player->addDamage(dmgrng);
            break;
        case 7:
            healthrng = rand() % 14 + 1;


            std::cout << "The chest contains a curse.....health stat loss... " << -healthrng <<std::endl;
            player->addHealth(-healthrng);

            break;
        case 8:
            goldrng = rand() % 14 + 1;


            std::cout << "The chest contains a curse.....gold stat loss... " << -goldrng <<std::endl;
            player->addGold(-goldrng);
            break;
        case 9:
            dmgrng = rand() % 5 + 1;

            std::cout << "The chest contains a curse.....damage stat loss... " << -dmgrng<< std::endl;
            player->addDamage(-dmgrng);
            break;

    }
    this->setCompleted();
}