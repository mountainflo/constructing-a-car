#include "FuelTank.h"

void FuelTank::Consume(double liters) {
    if(liters > 0){
        fillLevel -= liters;
    }
    if(fillLevel < RESERVE_FILL_LEVEL) {
        isOnReserve = true;
    }
    if(fillLevel < MAXIMUM_FILL_LEVEL) {
        isComplete = false;
    }
    if(fillLevel < 0.0) {
        fillLevel = 0.0;
    }
}

void FuelTank::Refuel(double liters) {
    if(liters > 0){
        fillLevel += liters;
    }
    if(fillLevel >= MAXIMUM_FILL_LEVEL) {
        fillLevel = MAXIMUM_FILL_LEVEL;
        isComplete = true;
    }
    if(fillLevel > RESERVE_FILL_LEVEL) {
        isOnReserve = false;
    }
    if(fillLevel < RESERVE_FILL_LEVEL) {
        isOnReserve = true;
    }
}

bool FuelTank::getIsOnReserve(){
    return isOnReserve;
}

bool FuelTank::getIsComplete(){
    return isComplete;
}

double FuelTank::getFillLevel(){
    return fillLevel;
}     