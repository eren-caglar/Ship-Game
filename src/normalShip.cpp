//
// Created by Lenovo on 14.03.2024.
//

#include <iostream>
#include "../inc/normalShip.h"
#include <random>
#include <ctime>



normalShip::normalShip() : Ship(FUEL,HEALTH,COIN) // important construction
{
    std::cout<<"Normal ship is created!"<<"\n";
}

normalShip::~normalShip(){
    std::cout<<"Normal ship has been destructed"<<"\n";
}

double normalShip::getHealth() {
    return health;
}

void normalShip::damageTaken(double _damage) {
    std::cout<<_damage<<" damage has been taken!"<<"\n";
    health -= _damage;
    std::cout<<"New health is "<<health<<"\n";
}

void normalShip::coinGained(int _coin) {
    std::cout<<_coin<<"has been taken"<<"\n";
    coin += _coin;
    std::cout<<"New coin amount is "<<coin<<"\n";
}

double normalShip::POE() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    auto probabilityOfEscape = static_cast<double>(random_number);
    std::cout<<"Probability of normal ship's escape is %"<< probabilityOfEscape << "\n"; //DUZELT her gemi icin
    return probabilityOfEscape;
}

int normalShip::getFuel() {
    return fuel;
}

void normalShip::FuelConsumed() {
    std::cout<<"Your current fuel is "<<fuel<<"\n";
    fuel -= CONSUMED_FUEL;
    std::cout<<"Now your fuel is decreased by "<<CONSUMED_FUEL<< " liter"<<"\n";
    std::cout<<"Your new fuel is "<<fuel<<"\n";

}

void normalShip::addCoin() { // adds 10 coin for abandonedPlanet
    std::cout<<"Your current coin is "<<coin<<"\n";
    coin += ADDED_COIN;
    std::cout<<"Now your coin is increased by "<<ADDED_COIN<<"\n";
    std::cout<<"Your new coin amount is "<<coin<<"\n";


}

int normalShip::getCoin() {
    return(coin);
}

void normalShip::coinSpent(int _coin) {
    std::cout<<"Your current coin amount is "<<coin<<"\n";
    std::cout<<"Now your coin is decreased by "<<_coin<<"\n";
    coin -= _coin;
    std::cout<<"Your new coin amount is "<<coin<<"\n";

}
