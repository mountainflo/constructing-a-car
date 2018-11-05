#ifndef FUEL_TANK_H
#define FUEL_TANK_H

class FuelTank
{
private:
    const double MAXIMUM_FILL_LEVEL = 60.0;
    const double RESERVE_FILL_LEVEL = 5.0;

    double _fill_level = 0.0;
    bool _is_on_reserve = false;
    bool _is_complete = false;

public:

    void consume(double liters) {
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

void refuel(double liters) {
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

bool get_is_on_reserve(){
    return _is_on_reserve;
}

bool get_is_complete(){
    return _is_complete;
}

double get_fill_level(){
    return _fill_level;
}  
    
};

#endif // FUEL_TANK_H