#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Class_Creatures.cpp"

class Combat {
public:
    creature player, enemy;

    void combat_start() {
        std::cout << "Combat started!" << std::endl;
        while (enemy.health > 0 && player.health > 0) {
            if (checkForDodge())
                continue;
            crit = checkForCrit();
            attack();
            nextTurn();
        }
        
        if (player.health <= 0) {
            std::cout << "Player defeated!" << std::endl;
        } else {
            std::cout << "Enemy defeated!" << std::endl;
        }
    }

private:
    int cooldownP = 0, cooldownE = 0;
    float dodgechanceP = (float)player.agility + (float)player.dexterity + (float)player.luck + 3.0f;
    float dodgechanceE = (float)enemy.agility + (float)enemy.dexterity + (float)enemy.luck + 3.0f;
    float critChanceP = 1.0f - 1.0f / ((float)dodgechanceP - 3.0f) - (float)dodgechanceE - 3.0f;
    float critChanceE = 1.0f - 1.0f / ((float)dodgechanceE - 3.0f) - (float)dodgechanceP - 3.0f;
    float critMultiP = (5.0f - 5.0f / ((float)player.luck + 2.0f)) * 0.5f + 1.0f;
    float critMultiE = (5.0f - 5.0f / ((float)enemy.luck + 2.0f)) * 0.5f + 1.0f;
    bool turn; // true : player, false : enemy
    int crit = 1;

    int attack() {
        int damage = 0;
        if (turn) {
            damage = player.strength - enemy.toughness;
            if (damage < 0) damage = 0;
            enemy.health -= damage * crit;
            std::cout << "Player deals " << damage * crit << " damage!" << std::endl;
        } else {
            damage = enemy.strength - player.toughness;
            if (damage < 0) damage = 0;
            player.health -= damage * crit;
            std::cout << "Enemy deals " << damage * crit << " damage!" << std::endl;
        }
        return damage;
    }

    void nextTurn() {
        if (cooldownP > cooldownE) {
            cooldownP -= cooldownE;
            cooldownE = enemy.agility;
            turn = false;
        } else if (cooldownE > cooldownP) {
            cooldownE -= cooldownP;
            cooldownP = player.agility;
            turn = true;
        } else {
            cooldownP = player.agility;
            cooldownE = enemy.agility;
            turn = (player.agility >= enemy.agility) ? true : false;
        }
    }

    int checkForCrit() {
        float random = (float)rand() / RAND_MAX;
        if (turn) {
            if (random < critChanceP) {
                std::cout << "Player critical hit!" << std::endl;
                return (int)critMultiP;
            } else {
                return 1;
            }
        } else {
            if (random < critChanceE) {
                std::cout << "Enemy critical hit!" << std::endl;
                return (int)critMultiE;
            } else {
                return 1;
            }
        }
    }

    bool checkForDodge() {
        float random = (float)rand() / RAND_MAX;
        if (turn) {
            if (random < 1.0f - (1.0f / dodgechanceE) + (1.0f / dodgechanceP)) {
                std::cout << "Enemy dodged!" << std::endl;
                return true;
            } else {
                return false;
            }
        } else {
            if (random < 1.0f - (1.0f / dodgechanceP) + (1.0f / dodgechanceE)) {
                std::cout << "Player dodged!" << std::endl;
                return true;
            } else {
                return false;
            }
        }
    }
};










