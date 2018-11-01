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

    void Consume(double liters){
        fuelTank->Consume(liters);
    }

    void Start(){
        IEngine::isRunning = true;
    }

    void Stop(){
        IEngine::isRunning = false;
    }

    /*bool getIsRunning(){
        return IEngine::IsRunning;
    }*/

};

#endif // ENGINE_CPP