#ifndef FUEL_TANK_DISPLAY_CPP
#define FUEL_TANK_DISPLAY_CPP

#include "IFuelTankDisplay.h"
#include "FuelTank.cpp"
#include <math.h>

class FuelTankDisplay : public IFuelTankDisplay
{
private:
    FuelTank* fuelTank;

public:
    FuelTankDisplay(FuelTank* fuelTank){
        this->fuelTank = fuelTank;
    }

    double getFillLevel(){
        IFuelTankDisplay::fillLevel = ((int) round(fuelTank->getFillLevel() * 100.0)) / 100.0;
        return IFuelTankDisplay::fillLevel;
    } 

    bool getIsOnReserve(){
        IFuelTankDisplay::isOnReserve = fuelTank->getIsOnReserve();
        return IFuelTankDisplay::isOnReserve;
    }

    bool getIsComplete(){
        IFuelTankDisplay::isComplete = fuelTank->getIsComplete();       
        return IFuelTankDisplay::isComplete;
    }
};

#endif // FUEL_TANK_DISPLAY_CPP