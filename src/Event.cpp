//
// Created by Lenovo on 12.03.2024.
//
#include "../inc/Ship.h"
#include "../inc/Event.h"
#include <iostream>



Event::Event():eventFinishFlag{0} {
    std::cout<<"Events are created!"<<"\n";
}

void Event::asteroidBelt (const std::unique_ptr<Ship> &Ship)
{   std::cout<<"Now you are in asteroid belt"<<"\n";
    Ship->damageTaken(10);
    if(Ship->getHealth()<0)
    {
        eventFinishFlag=1;
    }
}

void Event::abandonedPlanet (const std::unique_ptr<Ship> &Ship)
{
    std::cout<<"Now you are in abandoned planet"<<"\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int random_number = dis(gen);
    if(random_number > 50){ // good case, adding 10 coin
        std::cout<<"You are lucky! You gained 10 coin"<<"\n";
        Ship->addCoin();
    }
    else{ // bad case, space pirates are invoked;
        std::cout<<"You are unlucky! You will encounter with space pirates!"<<"\n";
        spacePirates (Ship);
    }
}

void Event::spacePirates(const std::unique_ptr<Ship> &Ship) {
    // there are 3 cases: escape, battle, bargain
    int selection{0};
    std::cout<<"Space pirates are waiting for you! Choose your destiny! Press the corresponding key"<<"\n";
    std::cout<<"1)Escape"<<"\n"<<"2)Battle"<<"\n"<<"3)Bargain"<<"\n";
    std::cin>>selection;
    if(selection == 1){ //Escape
        std::cout<<"You chose to escape!"<<"\n";
    double escapeChance = Ship->POE();
    if(Ship->getFuel()>33) {
            Ship->FuelConsumed();
        if (escapeChance >= 50.0) { // escape
            std::cout << "You were lucky! You have escaped!" << "\n";
            std::cout << "Your fuel is decreased by 33 because of escape" << "\n";
            if(Ship->getFuel()<=1){
                eventFinishFlag=1;
            }
        }
        else{

            std::cout <<"You were unlucky! You couldn't escape!" << "\n";
            std::cout<<"Space pirates are coming again!"<< "\n";
            Event::spacePirates(Ship);
        }
    }
    else{
        std::cout<<"You don't have enough fuel to escape! Space pirates are coming again!"<<"\n";
        std::cout<<"Make a different choice!"<<"\n";
        Event::spacePirates(Ship);
    }

    }
    else if(selection == 2){ //Battle
        std::cout<<"You chose to battle!"<<"\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        int random_number = dis(gen);
        if(random_number > 50){
            std::cout<<"You were lucky and you won the battle!"<<"\n";

        }
        else{
            std::cout<<"You were unlucky and you lost the battle!"<<"\n";
            Ship->damageTaken(30.0);
            if(Ship->getHealth()<=0)
            {
                eventFinishFlag=1;
            }
        }

    }
    else if(selection == 3){ //Bargain
        std::cout<<"You chose to bargain!"<<"\n";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        int random_number = dis(gen);
        if(random_number < 30){
            std::cout<<"You were really unlucky and you have to pay 30 coins to space pirates"<<"\n";
            Ship->coinSpent(30);
        }
        else if ((random_number > 30) && (random_number <= 70) )
        {
            std::cout<<"You were not really unlucky but you were not really luck too. You have pay 20 coins to space pirates"<<"\n";
            Ship->coinSpent(20);
        }

        else
        {
            std::cout<<"You were really lucky and you have to pay 10 coins to space pirates"<<"\n";
            Ship->coinSpent(10);
        }

    }
    else{
        std::cout<<"You have pressed the wrong key! Please press the right key again!"<<"\n"<<"\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        Event::spacePirates(Ship);
    }

}


void Event::finishTheGame(const std::unique_ptr<Ship> &Ship){
    std::cout<<"Congratulations, you finished the game! Here is your point!"<<"\n";
    std::cout <<"Your fuel is "<<Ship->getFuel()<<"\n"<<"Your coin is "<<Ship->getCoin()<<"\n"<<"Your health is "<<Ship->getHealth()<<"\n";
    double totalPoint = Ship->getFuel()*5 + Ship->getCoin()*10+Ship->getHealth()*10;
    std::cout<<"Your point is "<<totalPoint<<"\n"<<"\n";
}

int Event::getEventFinishFlag(){
    return eventFinishFlag;
}

int eventGenerator(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);
    int random_case = dis(gen);
    return random_case;
}



