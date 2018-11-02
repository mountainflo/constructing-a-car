#include "Engine.h"

void Engine::consume(double liters) {
    _fuel_tank->consume(liters);
}

void Engine::start() {
    _is_running = true;
}

void Engine::stop() {
    _is_running = false;
}

bool Engine::get_is_running(){
    return _is_running;
}