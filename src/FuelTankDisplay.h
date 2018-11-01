#ifndef FUEL_TANK_DISPLAY_H
#define FUEL_TANK_DISPLAY_H

#include "FuelTank.h"

class FuelTankDisplay
{
private:
    FuelTank* _fuel_tank;

public:
    FuelTankDisplay(FuelTank* fuel_tank) : _fuel_tank (fuel_tank){}

    double getFillLevel();

    bool getIsOnReserve();

    bool getIsComplete();

};

#endif // FUEL_TANK_DISPLAY_H