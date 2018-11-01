#ifndef FUEL_TANK_DISPLAY_CPP
#define FUEL_TANK_DISPLAY_CPP

#include "FuelTankDisplay.h"
#include "FuelTank.cpp"
#include <math.h>

class FuelTankDisplay : public IFuelTankDisplay
{
private:
    FuelTank* _fuel_tank;

public:
    FuelTankDisplay(FuelTank* fuel_tank) : _fuel_tank (fuel_tank){}

    double getFillLevel(){
        return ((int) round(_fuel_tank->getFillLevel() * 100.0)) / 100.0;
    } 

    bool getIsOnReserve(){
        return _fuel_tank->getIsOnReserve();
    }

    bool getIsComplete(){
        return _fuel_tank->getIsComplete();
    }
};

#endif // FUEL_TANK_DISPLAY_CPP