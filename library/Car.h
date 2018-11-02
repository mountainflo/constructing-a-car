#ifndef CAR_H
#define CAR_H

#include "FuelTankDisplay.h"
#include "FuelTank.h"
#include "Engine.h"
#include "autogen-CC-macros.h"

class Car
{

private:
    FuelTank _fuel_tank;
    Engine _engine;
    const double FUEL_CONSUMPTION = 0.0003;

public:

    FuelTankDisplay fuel_tank_display;

    Car() : Car(20){};

    Car(int fuel) : _fuel_tank(), _engine(&_fuel_tank), fuel_tank_display(&_fuel_tank) {
        refuel(fuel);
    }

    void engine_start();

    void engine_stop();

    /** \brief Refuel the fuel tank.
     *
     * \param liters count of liters to refuel the car
     */
    void refuel(double liters);

    void running_idle();

    bool get_engine_is_running();
 };

#endif // CAR_H