//
// Created by Lenovo on 14.03.2024.
//

#ifndef BIL142_PROJE_NORMALSHIP_H
#define BIL142_PROJE_NORMALSHIP_H
#include "Ship.h"
#include <iostream>

class normalShip : public Ship{
public:
    normalShip();
    double getHealth() override; // returns health
    void damageTaken(double _damage) override; // in case of battle ???
    void coinGained(int _coin) override;
    double POE() override; //probability of escape
    int getFuel() override; // returns fuel
    void FuelConsumed() override; // decreases fuel by 33
    void addCoin() override;
    void coinSpent(int _coin)  override;
    int getCoin() override;
    ~normalShip() override;

protected:

};


#endif //BIL142_PROJE_NORMALSHIP_H
