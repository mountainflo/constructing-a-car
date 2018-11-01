#include "Car.h"
#include <iostream>


bool Car::getEngineIsRunning(){
    return _engine.getIsRunning();
}

void Car::EngineStart() {
    if(_fuel_tank.getFillLevel() > 0.0){
        _engine.Start();
    } 
}

void Car::EngineStop() {
    _engine.Stop();
}

void Car::Refuel(double liters) {
    _fuel_tank.Refuel(liters);
}

void Car::RunningIdle() {
    if(_fuel_tank.getFillLevel() < FUEL_CONSUMPTION 
        || (_fuel_tank.getFillLevel() - FUEL_CONSUMPTION) < FUEL_CONSUMPTION){

        EngineStop();
        return;
    }

    if(getEngineIsRunning()) {
        _fuel_tank.Consume(FUEL_CONSUMPTION);
    }
}
