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
    FuelTank* fuelTank;
    Engine* engine;
    double fuelConsumption = 0.0003;

public:

    FuelTankDisplay* fuelTankDisplay;

    Car() : Car(20){};

    Car(int fuel){
        fuelTank = new FuelTank;
        fuelTankDisplay = new FuelTankDisplay(fuelTank);
        engine = new Engine(fuelTank);
        Refuel(fuel);
    }


    bool getEngineIsRunning(){
        return ICar::engineIsRunning;
    }

    void EngineStart(){
        if(fuelTank->getFillLevel() > 0.0){
            ICar::engineIsRunning = true;
            engine->Start();
        } 
    }

    void EngineStop(){
        ICar::engineIsRunning = false;
        engine->Stop();
    }

    void Refuel(double liters){
        fuelTank->Refuel(liters);
    }

    void RunningIdle(){
        if(fuelTank->getFillLevel() < fuelConsumption 
            || (fuelTank->getFillLevel() - fuelConsumption) < fuelConsumption){
            EngineStop();
            return;
        }
        if(getEngineIsRunning()) {
            fuelTank->Consume(fuelConsumption);
        }
    }

};

#endif // CAR_CPP