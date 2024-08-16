//
// Created by Lenovo on 14.03.2024.
//

#include <iostream>
#include "../inc/strongShip.h"
#include <random>
#include <ctime>



strongShip::strongShip() : Ship(FUEL,HEALTH,COIN) // important construction
{
    std::cout<<"Strong ship is created!"<<"\n";
}

strongShip::~strongShip(){
    std::cout<<"Strong ship has been destructed"<<"\n";
}

double strongShip::getHealth() {
    return health;
}

void strongShip::damageTaken(double _damage) {
    std::cout<<_damage*(STRONG_SHIP_COEFFICIENT)<<" damage has been taken!"<<"\n";
    health -= _damage *(STRONG_SHIP_COEFFICIENT);
    std::cout<<"New health is "<<health<<"\n";
}

void strongShip::coinGained(int _coin) {
    std::cout<<_coin<<"has been taken"<<"\n";
    coin += _coin;
    std::cout<<"New coin amount is "<<coin<<"\n";
}

double strongShip::POE() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    double probabilityOfEscape = static_cast<double>(random_number)*(STRONG_SHIP_COEFFICIENT);
    std::cout<<"Probability of strong ship's escape is %"<< probabilityOfEscape << "\n"; //DUZELT her gemi icin
    return probabilityOfEscape;
}

int strongShip::getFuel() {
    return fuel;
}

void strongShip::FuelConsumed() {
    std::cout<<"Your current fuel is "<<fuel<<"\n";
    fuel -= CONSUMED_FUEL;
    std::cout<<"Now your fuel is decreased by "<<CONSUMED_FUEL<< " liter"<<"\n";
    std::cout<<"Your new fuel is "<<fuel<<"\n";

}

void strongShip::addCoin() { // adds 10 coin for abandonedPlanet
    std::cout<<"Your current coin is "<<coin<<"\n";
    coin += ADDED_COIN;
    std::cout<<"Now your coin is increased by "<<ADDED_COIN<<"\n";
    std::cout<<"Your new coin amount is "<<coin<<"\n";


}

int strongShip::getCoin() {
    return(coin);
}

void strongShip::coinSpent(int _coin) {
    std::cout<<"Your current coin amount is "<<coin<<"\n";
    std::cout<<"Now your coin is decreased by "<<_coin<<"\n";
    coin -= _coin;
    std::cout<<"Your new coin amount is "<<coin<<"\n";

}
