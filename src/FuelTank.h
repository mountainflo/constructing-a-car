#ifndef I_FUEL_TANK_H
#define I_FUEL_TANK_H

class IFuelTank
{
public:

    virtual void Consume(double liters) = 0;

    virtual void Refuel(double liters) = 0;

protected:

    double fillLevel = 0.0;

    bool isOnReserve = false;

    bool isComplete = false;

};

#endif // I_FUEL_TANK_H