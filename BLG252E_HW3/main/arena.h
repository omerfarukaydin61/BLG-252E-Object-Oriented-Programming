#ifndef ARENA_H_
#define ARENA_H_

#include <iostream>
#include "pokemon.h"

using namespace std;

class Arena
{
public:
    void addPokemon(char type, string name, int hp, int damage);
    void simulateBattle();
    void restartTerrain();
    void spawnTerrain();
    void printRoundStats(int round, int heads);
    void isMatchOver();
    void printMatchResults();
    int getTerrainDuration();
    void setTerrainDuration(int num);
    string getCurrentTerrain();
    void setCurrentTerrain(string terrain);

private:
    string current_terrain;
    int terrain_duration = 0;
    static const int MAX_POKEMONS = 2;                    // define a constant for the array size
    Pokemon* pokemons[MAX_POKEMONS] = { nullptr, nullptr }; // declare and initialize an array of pointers to Pokemon
    int index = 0;                                        // keep track of the current index in the array
};

#endif