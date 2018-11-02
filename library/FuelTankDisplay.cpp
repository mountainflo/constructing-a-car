#include "FuelTankDisplay.h"
#include <math.h>


double FuelTankDisplay::get_fill_level(){
    return ((int) round(_fuel_tank->get_fill_level() * 100.0)) / 100.0;
} 

bool FuelTankDisplay::get_is_on_reserve(){
    return _fuel_tank->get_is_on_reserve();
}

bool FuelTankDisplay::get_is_complete(){
    return _fuel_tank->get_is_complete();
}
