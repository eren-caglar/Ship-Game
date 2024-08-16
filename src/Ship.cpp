//
// Created by Lenovo on 12.03.2024.
//
#include "../inc/Ship.h"
#include <iostream>

Ship::Ship(int _fuel, double _health, int _coin) : fuel{_fuel}, health{_health}, coin{_coin}{
    std::cout<<"Ship selection is started..."<<"\n";
}

Ship::~Ship(){
   std::cout<<"\n";
}


