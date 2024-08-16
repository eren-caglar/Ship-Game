//
// Created by Lenovo on 12.03.2024.
//

#ifndef BIL142_PROJE_EVENT_H
#define BIL142_PROJE_EVENT_H
#include "Ship.h"
#include "fastShip.h"
#include "iostream"
#include "memory"
#include <random>
#include <ctime>

class Event {
public:
    //Event icin constructor ekleyebilirsint;
    Event();
    void asteroidBelt(const std::unique_ptr<Ship> &Ship); // add damage and health check!!!
    void abandonedPlanet(const std::unique_ptr<Ship> &Ship);
    void spacePirates(const std::unique_ptr<Ship> &Ship);
    void finishTheGame(const std::unique_ptr<Ship> &Ship);
    int getEventFinishFlag();

private:
    int eventFinishFlag;

};

int eventGenerator(); // 1->asteroidBelt, 2->abandonedPlanet, 3->spacePirates
#endif //BIL142_PROJE_EVENT_H
