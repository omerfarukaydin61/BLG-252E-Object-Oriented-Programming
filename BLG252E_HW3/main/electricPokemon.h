/* @Author
 * Student Name: Omer Faruk AYDIN
 * Student ID : 150210726
 */
#ifndef ELECTRICPOKEMON_H_
#define ELECTRICPOKEMON_H_

#include <iostream>
#include "pokemon.h"
using namespace std;

class ElectricPokemon : public Pokemon
{
public:
    ElectricPokemon(string name, int hp, int damage); // constructor
    void powerUp(Pokemon* opponent) override;         // override powerUp function
    void attackTo(Pokemon* opponent) override;        // override attackTo function
    void resPowerUp();                                // reset powerUp
    void checkIsOwnTerrain(string terrain) override;  // check if the terrain is own terrain
};

#endif