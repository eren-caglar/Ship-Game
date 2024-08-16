#include <iostream>
#include "../inc/Ship.h"
#include "../inc/fastShip.h"
#include "../inc/normalShip.h"
#include "../inc/strongShip.h"
#include "../inc/Event.h"
#include <limits>

void startMenu();
void fastShipCreator();
void normalShipCreator();
void strongShipCreator();

int main() {
    int gameFinishFlag{0};
    int chosenShip{0};
    while(!gameFinishFlag) {
        startMenu();
        std::cin >> chosenShip;
        if (chosenShip == 1) {  //Normal Ship
            normalShipCreator();
        } else if (chosenShip == 2) { //Fast Ship
            fastShipCreator();
        } else if (chosenShip == 3){ //Strong Ship
            strongShipCreator();
        }
        else if (chosenShip == 4){
            std::cout<<"Quiting the game..."<< "\n";
            gameFinishFlag = 1;
        }
        else {
            std::cout<<"You have pressed the wrong key. Please try again!"<< "\n"<< "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }




    }
}

void startMenu(){
    std::cout << "Welcome!" << "\n";
    std::cout << "What is the type that you want for your ship?" << "\n";
    std::cout << "1)Normal ship" << "\n" << "2)Fast ship" << "\n" << "3)Strong Ship" << "\n";
    std::cout <<"4)Quit the game"<< "\n";
    std::cout << "Please press the corresponding button!" << "\n";
}

void fastShipCreator() {
    std::unique_ptr<Ship> fastShip1{new class fastShip()};
    std::unique_ptr<Event> event1{new class Event()};
    int eventCount{0};
    int eventGenerated{0};
    while ((!(event1->getEventFinishFlag())) && eventCount != 5) {
        eventGenerated = eventGenerator();
        if (eventGenerated == 1) { // 1->asteroidBelt
            std::cout << "Random event number: " << eventCount + 1 << "\n";
            event1->asteroidBelt(fastShip1);
            std::cout << "\n";
            eventCount++;
        } else if (eventGenerated == 2) { // 2->abandonedPlanet
            std::cout << "Random event number: " << eventCount + 1 << "\n";
            event1->abandonedPlanet(fastShip1);
            eventCount++;
            std::cout << "\n";
        } else { // 3->spacePirates
            std::cout << "Random event number: " << eventCount + 1 << "\n";
            event1->spacePirates(fastShip1);
            eventCount++;
            std::cout << "\n";
        }
        if (eventCount == 5 || (event1->getEventFinishFlag())) {
            event1->finishTheGame(fastShip1);
        }
    }
}

void normalShipCreator(){
    std::unique_ptr<Ship> normalShip1{new class normalShip()};
    std::unique_ptr<Event> event1{new class Event()};
    int eventCount{0};
    int eventGenerated{0};
    while ((!(event1->getEventFinishFlag())) && eventCount != 5) {
        eventGenerated = eventGenerator();
        if (eventGenerated == 1) { // 1->asteroidBelt
            std::cout << "Random event number: " << eventCount + 1 << "\n";
            event1->asteroidBelt(normalShip1);
            std::cout << "\n";
            eventCount++;
        } else if (eventGenerated == 2) { // 2->abandonedPlanet
            std::cout << "Random event number: " << eventCount + 1 << "\n";
            event1->abandonedPlanet(normalShip1);
            eventCount++;
            std::cout << "\n";
        } else { // 3->spacePirates
            std::cout << "Random event number: " << eventCount + 1 << "\n";
            event1->spacePirates(normalShip1);
            eventCount++;
            std::cout << "\n";
        }
        if (eventCount == 5 || (event1->getEventFinishFlag())) {
            event1->finishTheGame(normalShip1);
        }
    }
}

void strongShipCreator(){
    std::unique_ptr<Ship> strongShip1{new class strongShip()};
    std::unique_ptr<Event> event1{new class Event()};
    int eventCount{0};
    int eventGenerated{0};
    while ((!(event1->getEventFinishFlag())) && eventCount != 5) {
        eventGenerated = eventGenerator();
        if (eventGenerated == 1) { // 1->asteroidBelt
            std::cout << "Random event number: " << eventCount + 1 << "\n";
            event1->asteroidBelt(strongShip1);
            std::cout << "\n";
            eventCount++;
        } else if (eventGenerated == 2) { // 2->abandonedPlanet
            std::cout << "Random event number: " << eventCount + 1 << "\n";
            event1->abandonedPlanet(strongShip1);
            eventCount++;
            std::cout << "\n";
        } else { // 3->spacePirates
            std::cout << "Random event number: " << eventCount + 1 << "\n";
            event1->spacePirates(strongShip1);
            eventCount++;
            std::cout << "\n";
        }
        if (eventCount == 5 || (event1->getEventFinishFlag())) {
            event1->finishTheGame(strongShip1);
        }
    }
}
