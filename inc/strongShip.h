//
// Created by Lenovo on 14.03.2024.
//

#ifndef BIL142_PROJE_STRONGSHIP_H
#define BIL142_PROJE_STRONGSHIP_H
#include "Ship.h"
#include <iostream>

class strongShip : public Ship{
public:
    strongShip();
    double getHealth() override; // returns health
    void damageTaken(double _damage) override; // in case of battle ???
    void coinGained(int _coin) override;
    double POE() override; //probability of escape
    int getFuel() override; // returns fuel
    void FuelConsumed() override; // decreases fuel by 33
    void addCoin() override;
    void coinSpent(int _coin)  override;
    int getCoin() override;
    ~strongShip() override;

protected:

};




#endif //BIL142_PROJE_STRONGSHIP_H
