#ifndef ENGINE_CPP
#define ENGINE_CPP

#include "IEngine.h"

class Engine : public IEngine
{

private:
    FuelTank* fuelTank;

public:

    Engine(FuelTank* fuelTank){
        this->fuelTank = fuelTank;
    }

    void Consume(double liters) override {
        fuelTank->Consume(liters);
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