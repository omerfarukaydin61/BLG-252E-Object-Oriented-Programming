/* @Author
 * Student Name: Omer Faruk AYDIN
 * Student ID : 150210726
 */
#ifndef PSYCHICPOKEMON_H_
#define PSYCHICPOKEMON_H_

#include <iostream>
#include "pokemon.h"
using namespace std;

class PsychicPokemon : public Pokemon
{
public:
    PsychicPokemon(string name, int hp, int damage); // constructor
    void powerUp(Pokemon* opponent) override;        // override powerUp function
    void attackTo(Pokemon* opponent) override;       // override attackTo function
    void resPowerUp();                               // reset powerUp
    void checkIsOwnTerrain(string terrain) override; // check if the terrain is own terrain
};

#endif