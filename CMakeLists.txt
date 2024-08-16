cmake_minimum_required(VERSION 3.27)
project(Bil142_Proje)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bil142_Proje src/main.cpp
        inc/Ship.h
        src/Ship.cpp
        inc/fastShip.h
        src/fastShip.cpp
        inc/Event.h
        src/Event.cpp
        inc/normalShip.h
        src/normalShip.cpp
        inc/strongShip.h
        src/strongShip.cpp
)
