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

    void consume(double liters);
    void refuel(double liters);

    bool get_is_on_reserve();
    bool get_is_complete();
    double get_fill_level();
    
};

#endif // FUEL_TANK_H