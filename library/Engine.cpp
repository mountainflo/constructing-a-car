#include "Engine.h"

void Engine::Consume(double liters) {
    _fuel_tank->Consume(liters);
}

void Engine::Start() {
    isRunning = true;
}

void Engine::Stop() {
    isRunning = false;
}

bool Engine::getIsRunning(){
    return isRunning;
}