#ifndef FUEL_TANK_CPP
#define FUEL_TANK_CPP

#include "FuelTank.h"

 

class FuelTank : public IFuelTank
{

private:
    const double MAXIMUM_FILL_LEVEL = 60.0;
    const double RESERVE_FILL_LEVEL = 5.0;

public:

    void Consume(double liters) override {
        if(liters > 0){
            IFuelTank::fillLevel -= liters;
        }
        if(IFuelTank::fillLevel < RESERVE_FILL_LEVEL) {
            IFuelTank::isOnReserve = true;
        }
        if(IFuelTank::fillLevel < MAXIMUM_FILL_LEVEL) {
            IFuelTank::isComplete = false;
        }
        if(IFuelTank::fillLevel < 0.0) {
            IFuelTank::fillLevel = 0.0;
        }
    };

    void Refuel(double liters) override {
        if(liters > 0){
            IFuelTank::fillLevel += liters;
        }
        if(IFuelTank::fillLevel >= MAXIMUM_FILL_LEVEL) {
            IFuelTank::fillLevel = MAXIMUM_FILL_LEVEL;
            IFuelTank::isComplete = true;
        }
        if(IFuelTank::fillLevel > RESERVE_FILL_LEVEL) {
            IFuelTank::isOnReserve = false;
        }
        if(IFuelTank::fillLevel < RESERVE_FILL_LEVEL) {
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