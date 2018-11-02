#include "FuelTank.h"

void FuelTank::consume(double liters) {
    if(liters > 0){
        _fill_level -= liters;
    }
    if(_fill_level < RESERVE_FILL_LEVEL) {
        _is_complete = true;
    }
    if(_fill_level < MAXIMUM_FILL_LEVEL) {
        _is_complete = false;
    }
    if(_fill_level < 0.0) {
        _fill_level = 0.0;
    }
}

void FuelTank::refuel(double liters) {
    if(liters > 0){
        _fill_level += liters;
    }
    if(_fill_level >= MAXIMUM_FILL_LEVEL) {
        _fill_level = MAXIMUM_FILL_LEVEL;
        _is_complete = true;
    }
    if(_fill_level > RESERVE_FILL_LEVEL) {
        _is_on_reserve = false;
    }
    if(_fill_level < RESERVE_FILL_LEVEL) {
        _is_on_reserve = true;
    }
}

bool FuelTank::get_is_on_reserve(){
    return _is_on_reserve;
}

bool FuelTank::get_is_complete(){
    return _is_complete;
}

double FuelTank::get_fill_level(){
    return _fill_level;
}     