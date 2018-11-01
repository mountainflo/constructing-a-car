#ifndef I_FUEL_TANK_DISPLAY_H
#define I_FUEL_TANK_DISPLAY_H

class IFuelTankDisplay
{
protected:

    double fillLevel = 0.0;

    bool isOnReserve = false;

    bool isComplete = false;
};

#endif // I_FUEL_TANK_DISPLAY_H