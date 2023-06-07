/* @Author
 * Student Name: Omer Faruk AYDIN
 * Student ID : 150210726
 */
#include <iostream>
#include "electricPokemon.h"
using namespace std;

ElectricPokemon::ElectricPokemon(string name, int hp, int damage) // constructor
    : Pokemon(name, hp, damage, 0.2, 3) {};
void ElectricPokemon::powerUp(Pokemon* opponent) // override powerUp function
{
    if (getRechargeCount() == 0) // if recharge count is 0
    {
        if (rand() % 10 <= 10 * getPowerUpChance()) // if random number is less than or equal to power up chance
        {
            setInitialDamage(3 * getDefDamage()); // set initial damage to 3 times of default damage
            setRechargeCount(getRecharge());      // set recharge count to recharge
            setIsPowerUp(true);                   // set is power up to true
        }
    }
    else
    {
        setRechargeCount(getRechargeCount() - 1); // else, decrease recharge count by 1
    }
};

void ElectricPokemon::attackTo(Pokemon* opponent) // override attackTo function
{
    if (getIsConfused() == false) // if is confused is false
    {
        opponent->setHitPoints(opponent->getHitPoints() - getInitialDamage()); // decrease opponent's hit points by initial damage
    }
    else if (getIsConfused() == true) // if is confused is true
    {
        setIsConfusedCount(getIsConfusedCount() - 1); // decrease is confused count by 1
        if (getIsConfusedCount() == 0)                // if is confused count is 0
        {
            setIsConfused(false); // set is confused to false
        }
    } // no damage is dealt to the opponent
};
void ElectricPokemon::resPowerUp() // override resPowerUp function
{
    setInitialDamage(getDefDamage()); // set initial damage to default damage
    setIsPowerUp(false);              // set is power up to false
}
void ElectricPokemon::checkIsOwnTerrain(string terrain) // override checkIsOwnTerrain function
{
    (terrain == "ELECTRIC") ? setIsOwnTerrain(true) : setIsOwnTerrain(false); // if terrain is electric, set is own terrain to true, else set it to false
}
