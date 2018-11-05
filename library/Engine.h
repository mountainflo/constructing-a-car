#ifndef ENGINE_H
#define ENGINE_H

#include "FuelTank.h"

class Engine
{
private:
    FuelTank* _fuel_tank;
    bool _is_running = false;

public:

    Engine(FuelTank* fuel_tank) : _fuel_tank{fuel_tank} {};

    void consume(double liters) {
	    _fuel_tank->consume(liters);
	}

	void start() {
	    _is_running = true;
	}

	void stop() {
	    _is_running = false;
	}

	bool get_is_running(){
	    return _is_running;
	}
    
};


#endif // ENGINE_H