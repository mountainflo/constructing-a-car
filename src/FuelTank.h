#ifndef FUEL_TANK_H
#define FUEL_TANK_H

class FuelTank
{
private:
    const double MAXIMUM_FILL_LEVEL = 60.0;
    const double RESERVE_FILL_LEVEL = 5.0;

    double fillLevel = 0.0;
    bool isOnReserve = false;
    bool isComplete = false;

public:

    void Consume(double liters);
    void Refuel(double liters);

    bool getIsOnReserve();
    bool getIsComplete();
    double getFillLevel();
    
};

#endif // FUEL_TANK_H