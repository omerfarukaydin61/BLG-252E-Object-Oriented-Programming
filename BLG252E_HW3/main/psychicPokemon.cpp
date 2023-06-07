/* @Author
 * Student Name: Omer Faruk AYDIN
 * Student ID : 150210726
 */
#include <iostream>
#include "psychicPokemon.h"

using namespace std;

PsychicPokemon::PsychicPokemon(string name, int hp, int damage) // constructor
    : Pokemon(name, hp, damage, 0.3, 5) {};
void PsychicPokemon::powerUp(Pokemon* opponent) // override powerUp function
{
    if (getRechargeCount() == 0) // if recharge count is 0
    {
        if (rand() % 10 <= 10 * getPowerUpChance()) // if random number is less than or equal to power up chance
        {
            setRechargeCount(getRecharge());          // set recharge count to recharge
            setIsPowerUp(true);                       // set is power up to true
            if (opponent->getIsOwnTerrain() == false) // if opponent's terrain is not own terrain
            {
                opponent->setIsConfused(true);   // set is confused to true
                opponent->setIsConfusedCount(3); // set is confused count to 3
            }
        }
    }
    else
    {
        setRechargeCount(getRechargeCount() - 1); // else, decrease recharge count by 1
    }
};
void PsychicPokemon::attackTo(Pokemon* opponent) // override attackTo function
{
    if (getIsOwnTerrain() == false) // if is own terrain is false
    {
        opponent->setHitPoints(opponent->getHitPoints() - getInitialDamage()); // decrease opponent's hit points by initial damage
    }
    else if (getIsOwnTerrain() == true) // if is own terrain is true
    {
        opponent->setHitPoints(opponent->getHitPoints() - 2 * getInitialDamage()); // decrease opponent's hit points by 2 times of initial damage
    }
};
void PsychicPokemon::resPowerUp() // override resPowerUp function
{
    setInitialDamage(getDefDamage()); // set initial damage to default damage
    setIsPowerUp(false);              // set is power up to false
};
void PsychicPokemon::checkIsOwnTerrain(string terrain) // override checkIsOwnTerrain function
{
    (terrain == "PSYCHIC") ? setIsOwnTerrain(true) : setIsOwnTerrain(false); // if terrain is psychic, set is own terrain to true, else set it to false
};
