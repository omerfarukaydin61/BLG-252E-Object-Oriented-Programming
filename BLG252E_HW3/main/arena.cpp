/* @Author
 * Student Name: Omer Faruk AYDIN
 * Student ID : 150210726
 */
#include <iostream>
#include "arena.h"
#include "electricPokemon.h"
#include "psychicPokemon.h"
using namespace std;

void Arena::addPokemon(char type, string name, int hp, int damage) // add a pokemon to the arena
{
    if (type == 'e') // if the type is electric
    {
        pokemons[index] = new ElectricPokemon(name, hp, damage); // create a new ElectricPokemon object
        cout << "\n\nElectric Pokemon " << name << " has entered the arena." << endl;
        cout << "Class: Electric" << endl;
        cout << "Name: " << name << endl;
        cout << "HP: " << hp << endl;
        cout << "Damage: " << damage << endl;
        index++;
    }
    else if (type == 'p') // if the type is psychic
    {
        pokemons[index] = new PsychicPokemon(name, hp, damage); // create a new PsychicPokemon object
        cout << "\n\nPsychic Pokemon " << name << " has entered the arena." << endl;
        cout << "Class: Psychic" << endl;
        cout << "Name: " << name << endl;
        cout << "HP: " << hp << endl;
        cout << "Damage: " << damage << endl;
        index++;
    }
}
void Arena::simulateBattle() // simulate a battle between two pokemons
{
    int round = 1;
    while (!pokemons[0]->getIsFainted() && !pokemons[1]->getIsFainted()) // while both pokemons are not fainted
    {
        int random_index = rand() % MAX_POKEMONS;     // generate a random index between 0 and 2
        Pokemon* first = pokemons[random_index];      // get the first pokemon
        Pokemon* second = pokemons[1 - random_index]; // get the second pokemon

        if (getTerrainDuration() == 0) // if the terrain duration is 0
        {
            spawnTerrain(); // spawn a new terrain
            for (int i = 0; i < MAX_POKEMONS; i++)
            {
                pokemons[i]->checkIsOwnTerrain(getCurrentTerrain()); // check if the terrain is own terrain
            }
        }

        first->powerUp(second);  // power up the first pokemon
        first->attackTo(second); // attack the second pokemon

        if (!second->getIsFainted()) // if the second pokemon is not fainted
        {
            second->powerUp(first);  // power up the second pokemon
            second->attackTo(first); // attack the first pokemon
        }

        printRoundStats(round, random_index);         // print the stats of the round
        round++;                                      // increment the round
        setTerrainDuration(getTerrainDuration() - 1); // decrement the terrain duration
        first->resPowerUp();                          // reset the power up of the first pokemon
        second->resPowerUp();                         // reset the power up of the second pokemon
    }
    isMatchOver();    // check if the match is over
    restartTerrain(); // restart the terrain
};
void Arena::spawnTerrain() // spawn a terrain
{
    int random_terrain = rand() % 100; // generate a random number between 0 and 2
    if (random_terrain < 20)           // if the random number is less than 20
    {
        setCurrentTerrain("ELECTRIC"); // set the current terrain to electric
        setTerrainDuration(5);         // set the terrain duration to 5
    }
    else if (random_terrain < 40) // if the random number is less than 40
    {
        setCurrentTerrain("PSYCHIC"); // set the current terrain to psychic
        setTerrainDuration(5);        // set the terrain duration to 5
    }
    else
    {
        setCurrentTerrain("NONE"); // set the current terrain to none
        setTerrainDuration(0);     // set the terrain duration to 0
    }
}
void Arena::restartTerrain() // restart the terrain
{
    setCurrentTerrain("NONE"); // set the current terrain to none
    setTerrainDuration(0);     // set the terrain duration to 0
}
void Arena::printRoundStats(int round, int heads) // print the stats of the round
{
    cout << "\n\nRound: " << round << endl;
    cout << "Current Terrain: " << getCurrentTerrain() << endl;
    cout << pokemons[heads]->getName() << " goes first." << endl;
    if (pokemons[0]->getIsPowerUp()) // if the first pokemon is powered up
    {
        cout << pokemons[0]->getName() << " has initiated a power up." << endl;
    }
    if (pokemons[1]->getIsPowerUp())
    {
        cout << pokemons[1]->getName() << " has initiated a power up." << endl;
    }
    cout << pokemons[0]->getName() << "HP: " << (pokemons[0]->getHitPoints() > 0 ? pokemons[0]->getHitPoints() : 0) << endl;
    cout << pokemons[1]->getName() << "HP: " << (pokemons[1]->getHitPoints() > 0 ? pokemons[1]->getHitPoints() : 0) << endl;
    (pokemons[0]->getHitPoints() > pokemons[1]->getHitPoints()) ? cout << pokemons[0]->getName() << " is in the lead!" << endl : cout << pokemons[1]->getName() << "is in the lead!" << endl;
}
void Arena::isMatchOver() // check if the match is over
{
    if (pokemons[0]->getIsFainted() || pokemons[1]->getIsFainted()) // if one of the pokemons is fainted
    {
        printMatchResults();
        for (int i = 0; i < MAX_POKEMONS; i++) // iterate through the pokemons
        {
            delete pokemons[i];    // delete the dynamic object
            pokemons[i] = nullptr; // set the pointer to null
        }
        index = 0; // reset the index
    }
}
void Arena::printMatchResults() // print the match results
{
    cout << "\n\nMatch Results :" << endl;
    cout << ((pokemons[0]->getIsFainted()) ? pokemons[1]->getName() : pokemons[0]->getName()) << " has won the match!\n\n"
        << endl;
}
int Arena::getTerrainDuration() { return this->terrain_duration; };
void Arena::setTerrainDuration(int num) { this->terrain_duration = num; };
string Arena::getCurrentTerrain() { return this->current_terrain; };
void Arena::setCurrentTerrain(string terrain) { this->current_terrain = terrain; }
