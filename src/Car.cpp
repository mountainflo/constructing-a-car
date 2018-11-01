#ifndef CAR_CPP
#define CAR_CPP

#include "ICar.h"
#include "FuelTankDisplay.cpp"
#include "FuelTank.cpp"
#include "Engine.cpp"
#include <iostream>

class Car : public ICar
{

private:
    FuelTank* _fuel_tank;
    Engine* _engine;
    const double FUEL_CONSUMPTION = 0.0003;

public:

    FuelTankDisplay* fuel_tank_display;

    Car() : Car(20){};

    Car(int fuel) : _fuel_tank(){
        _fuel_tank = new FuelTank();
        fuel_tank_display = new FuelTankDisplay(_fuel_tank);
        _engine = new Engine(_fuel_tank);
        Refuel(fuel);
    }


    bool getEngineIsRunning(){
        return _engine->getIsRunning();
    }

    void EngineStart() override {
        if(_fuel_tank->getFillLevel() > 0.0){
            _engine->Start();
        } 
    }

    void EngineStop() override {
        _engine->Stop();
    }

    void Refuel(double liters) override {
        _fuel_tank->Refuel(liters);
    }

    void RunningIdle() override {
        if(_fuel_tank->getFillLevel() < FUEL_CONSUMPTION 
            || (_fuel_tank->getFillLevel() - FUEL_CONSUMPTION) < FUEL_CONSUMPTION){

            EngineStop();
            return;
        }
        if(getEngineIsRunning()) {
            _fuel_tank->Consume(FUEL_CONSUMPTION);
        }
    }

};

#endif // CAR_CPP