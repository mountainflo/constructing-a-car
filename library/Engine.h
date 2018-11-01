#ifndef ENGINE_H
#define ENGINE_H

#include "FuelTank.h"

class Engine
{
private:
    FuelTank* _fuel_tank;
    bool isRunning = false;

public:

    Engine(FuelTank* fuel_tank) : _fuel_tank{fuel_tank} {};

    void Consume(double liters);

    void Start();

    void Stop();

    bool getIsRunning();
    
};


#endif // ENGINE_H