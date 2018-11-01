#include "Engine.h"

Engine(FuelTank* fuel_tank) : _fuel_tank(fuel_tank){}

void Engine::Consume(double liters) {
    _fuel_tank->Consume(liters);
}

void Engine::EngineStart() {
    isRunning = true;
}

void Engine::Stop() {
    isRunning = false;
}

bool Engine::getIsRunning(){
    return isRunning;
}