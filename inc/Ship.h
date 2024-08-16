//
// Created by Lenovo on 12.03.2024.
//

#ifndef BIL142_PROJE_SHIP_H
#define BIL142_PROJE_SHIP_H
#include <iostream>

constexpr int FUEL = 100;
constexpr double HEALTH = 100.0;
constexpr int COIN = 0;
constexpr int CONSUMED_FUEL = 33;
constexpr int ADDED_COIN = 10;
constexpr double FAST_SHIP_COEFFICIENT = 1.5;
constexpr double STRONG_SHIP_COEFFICIENT = 0.5;

class Ship {
public:
    Ship(int _fuel, double _health,int _coin); // pass the values of fuel, health and coin
    virtual double getHealth() = 0; // returns the current health
    virtual void damageTaken(double _damage) = 0; //in case of taking damage
    virtual void coinGained(int _coin) = 0; // adds specific value of coin
    virtual double POE() = 0; //probability of escape
    virtual int getFuel() = 0; // returns the current fuel
    virtual void FuelConsumed() = 0; // decrement of fuel by 33 because of escape
    virtual int getCoin() = 0; // returns the coin amount
    virtual void addCoin() = 0; // adds 10 coin for abandonedPlanet
    virtual void coinSpent(int _coin) = 0; // spends coin for space pirates in the case of bargain
    virtual ~Ship();

protected:
    int fuel;
    double health;
    int coin;
};






#endif //BIL142_PROJE_SHIP_H
