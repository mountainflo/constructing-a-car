#ifndef FUEL_TANK_DISPLAY_H
#define FUEL_TANK_DISPLAY_H

#include "FuelTank.h"
#include <math.h>

class FuelTankDisplay
{
private:
    FuelTank* _fuel_tank;

public:
    FuelTankDisplay(FuelTank* fuel_tank) : _fuel_tank (fuel_tank){}

	double get_fill_level(){
	    return ((int) round(_fuel_tank->get_fill_level() * 100.0)) / 100.0;
	} 

	bool get_is_on_reserve(){
	    return _fuel_tank->get_is_on_reserve();
	}

	bool get_is_complete(){
	    return _fuel_tank->get_is_complete();
	}

};

#endif // FUEL_TANK_DISPLAY_H