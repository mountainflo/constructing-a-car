#include "FuelTankDisplay.h"
#include <math.h>


double FuelTankDisplay::getFillLevel(){
    return ((int) round(_fuel_tank->getFillLevel() * 100.0)) / 100.0;
} 

bool FuelTankDisplay::getIsOnReserve(){
    return _fuel_tank->getIsOnReserve();
}

bool FuelTankDisplay::getIsComplete(){
    return _fuel_tank->getIsComplete();
}
