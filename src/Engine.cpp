#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "IEngine.h"

class Engine : public IEngine
{

private:
    FuelTank* _fuel_tank;

public:

    Engine(FuelTank* fuel_tank) : _fuel_tank(fuel_tank){}

    void Consume(double liters) override {
        _fuel_tank->Consume(liters);
    }

    void Start() override {
        IEngine::isRunning = true;
    }

    void Stop() override {
        IEngine::isRunning = false;
    }

    bool getIsRunning(){
        return IEngine::isRunning;
    }

};

#endif // ENGINE_CPP