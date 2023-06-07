/* @Author
 * Student Name: Omer Faruk AYDIN
 * Student ID : 150210726
 */
#ifndef POKEMON_H_
#define POKEMON_H_

#include <iostream>
using namespace std;

class Pokemon
{
public:
    Pokemon(string name, int hp, int damage,
        float powerUp_chance, int recharge);      // constructor
    virtual void powerUp(Pokemon*) {};                // virtual function for polymorphism
    virtual void attackTo(Pokemon*) {};               // virtual function for polymorphism
    virtual void checkIsOwnTerrain(string terrain) {}; // virtual function for polymorphism
    virtual void resPowerUp() {};                      // virtual function for polymorphism
    virtual ~Pokemon() {};                             // virtual destructor
    string getName();                                 // getter and setter functions
    int getHitPoints();
    void setHitPoints(int hp);
    int getRechargeCount();
    void setRechargeCount(int num);
    bool getIsOwnTerrain();
    void setIsOwnTerrain(bool isOwnTerrain);
    bool getIsPowerUp();
    void setIsPowerUp(bool isPowerUp);
    float getPowerUpChance();
    int getRecharge();
    bool getIsFainted();
    void setInitialDamage(int damage);
    int getInitialDamage();
    bool getIsConfused();
    void setIsConfused(bool isConfused);
    const int getDefDamage();
    int getIsConfusedCount();
    void setIsConfusedCount(int isConfusedCount);

private:
    string name;                     // name of the pokemon
    const int DEF_DAMAGE;            // default damage of the pokemon
    int hit_points;                  // hit points of the pokemon
    int initial_damage = DEF_DAMAGE; // initial damage of the pokemon
    const float power_up_chance;     // power up chance of the pokemon
    const int recharge;              // recharge count of the pokemon
    bool isOwnTerrain = false;       // is own terrain of the pokemon
    bool isPowerUp = false;          // is power up of the pokemon
    int rechargeCount = 0;           // recharge count of the pokemon
    bool isFainted = 0;              // is fainted of the pokemon
    bool isConfused = false;         // is confused of the pokemon for electric pokemons
    int isConfusedCount = 0;         // is confused count of the pokemon for electric pokemons
};

#endif