//
// Created by Lenovo on 12.03.2024.
//

#ifndef BIL142_PROJE_FASTSHIP_H
#define BIL142_PROJE_FASTSHIP_H
#include "Ship.h"
#include <iostream>

class fastShip : public Ship{
public:
    fastShip();
    double getHealth() override; // returns health
    void damageTaken(double _damage) override; // in case of battle ???
    void coinGained(int _coin) override;
    double POE() override; //probability of escape
    int getFuel() override; // returns fuel
    void FuelConsumed() override; // decreases fuel by 33
    void addCoin() override;
    void coinSpent(int _coin)  override;
    int getCoin() override;
    ~fastShip() override;

protected:

};



#endif //BIL142_PROJE_FASTSHIP_H
