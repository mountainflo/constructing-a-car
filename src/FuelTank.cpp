#ifndef FUEL_TANK_CPP
#define FUEL_TANK_CPP

#include "IFuelTank.h"

class FuelTank : public IFuelTank
{

private:
    double maximumFillLevel = 60.0;
    double reserveFillLevel = 5.0;

public:

    void Consume(double liters){
        if(liters > 0){
            IFuelTank::fillLevel -= liters;
        }
        if(IFuelTank::fillLevel < reserveFillLevel) {
            IFuelTank::isOnReserve = true;
        }
        if(IFuelTank::fillLevel < maximumFillLevel) {
            IFuelTank::isComplete = false;
        }
        if(IFuelTank::fillLevel < 0.0) {
            IFuelTank::fillLevel = 0.0;
        }
    };

    void Refuel(double liters){
        if(liters > 0){
            IFuelTank::fillLevel += liters;
        }
        if(IFuelTank::fillLevel >= maximumFillLevel) {
            IFuelTank::fillLevel = maximumFillLevel;
            IFuelTank::isComplete = true;
        }
        if(IFuelTank::fillLevel > reserveFillLevel) {
            IFuelTank::isOnReserve = false;
        }
        if(IFuelTank::fillLevel < reserveFillLevel) {
            IFuelTank::isOnReserve = true;
        }
    };

    bool getIsOnReserve(){
        return IFuelTank::isOnReserve;
    };

    bool getIsComplete(){
        return IFuelTank::isComplete;
    };

    double getFillLevel(){
        return IFuelTank::fillLevel;
    };      
};

#endif // FUEL_TANK_CPP