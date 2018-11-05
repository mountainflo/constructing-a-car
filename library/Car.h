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

    bool get_engine_is_running(){
	    return _engine.get_is_running();
	}

	void engine_start() {
	    if(_fuel_tank.get_fill_level() > 0.0){
	        _engine.start();
	    } 
	}

	void engine_stop() {
	    _engine.stop();
	}

	void refuel(double liters) {
	    _fuel_tank.refuel(liters);
	}

	void running_idle() {
	    if(_fuel_tank.get_fill_level() < FUEL_CONSUMPTION 
	        || (_fuel_tank.get_fill_level() - FUEL_CONSUMPTION) < FUEL_CONSUMPTION){

	        engine_stop();
	        return;
	    }

	    if(get_engine_is_running()) {
	        _fuel_tank.consume(FUEL_CONSUMPTION);
	    }
	}
 };

#endif // CAR_H