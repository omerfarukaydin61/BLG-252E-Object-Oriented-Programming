/* @Author
 * Student Name: Omer Faruk AYDIN
 * Student ID : 150210726
 */
#include <iostream>
#include "pokemon.h"
using namespace std;

Pokemon::Pokemon(string name, int hp, int damage,
    float powerUp_chance, int recharge)
    : name(name), DEF_DAMAGE(damage), hit_points(hp),
    power_up_chance(powerUp_chance), recharge(recharge) {};

string Pokemon::getName() { return this->name; }
int Pokemon::getHitPoints() { return this->hit_points; }
void Pokemon::setHitPoints(int hp) { this->hit_points = hp; }
int Pokemon::getRechargeCount() { return this->rechargeCount; }
void Pokemon::setRechargeCount(int num) { this->rechargeCount = num; } // set recharge count of the pokemon
bool Pokemon::getIsOwnTerrain() { return this->isOwnTerrain; }
void Pokemon::setIsOwnTerrain(bool isOwnTerrain) { this->isOwnTerrain = isOwnTerrain; }
bool Pokemon::getIsPowerUp() { return this->isPowerUp; }
void Pokemon::setIsPowerUp(bool isPowerUp) { this->isPowerUp = isPowerUp; }
float Pokemon::getPowerUpChance() { return this->power_up_chance; }
int Pokemon::getRecharge() { return this->recharge; }
bool Pokemon::getIsFainted() { return (getHitPoints() > 0) ? false : true; }  // if hit points is greater than 0, return false, else return true
void Pokemon::setInitialDamage(int damage) { this->initial_damage = damage; } // set initial damage of the pokemon
int Pokemon::getInitialDamage() { return this->initial_damage; }
bool Pokemon::getIsConfused() { return this->isConfused; }
void Pokemon::setIsConfused(bool isConfused) { this->isConfused = isConfused; }
const int Pokemon::getDefDamage() { return this->DEF_DAMAGE; }
int Pokemon::getIsConfusedCount() { return this->isConfusedCount; }
void Pokemon::setIsConfusedCount(int isConfusedCount) { this->isConfusedCount = isConfusedCount; }
