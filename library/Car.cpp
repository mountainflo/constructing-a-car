#include "Car.h"
#include <iostream>


bool Car::get_engine_is_running(){
    return _engine.get_is_running();
}

void Car::engine_start() {
    if(_fuel_tank.get_fill_level() > 0.0){
        _engine.start();
    } 
}

void Car::engine_stop() {
    _engine.stop();
}

void Car::refuel(double liters) {
    _fuel_tank.refuel(liters);
}

void Car::running_idle() {
    if(_fuel_tank.get_fill_level() < FUEL_CONSUMPTION 
        || (_fuel_tank.get_fill_level() - FUEL_CONSUMPTION) < FUEL_CONSUMPTION){

        engine_stop();
        return;
    }

    if(get_engine_is_running()) {
        _fuel_tank.consume(FUEL_CONSUMPTION);
    }
}
