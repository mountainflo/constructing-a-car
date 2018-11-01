#ifndef CAR_H
#define CAR_H

#include "FuelTankDisplay.h"
#include "FuelTank.h"
#include "Engine.h"
#include "autogen-CC-macros.h"

class Car
{

private:
    FuelTank _fuel_tank;
    Engine _engine;
    const double FUEL_CONSUMPTION = 0.0003;

public:

    FuelTankDisplay fuel_tank_display;

    Car() : Car(20){};

    Car(int fuel) : _fuel_tank(), _engine(&_fuel_tank), fuel_tank_display(&_fuel_tank) {
        Refuel(fuel);
    }

    void EngineStart();

    void EngineStop();

    void Refuel(double liters);

    void RunningIdle();

    bool getEngineIsRunning();
};

#endif // CAR_H