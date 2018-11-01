#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
    const FuelTank* _fuel_tank;
    bool isRunning = false;

public:

    Engine(const FuelTank* fuel_tank) : _fuel_tank{fuel_tank} {};

    virtual void Consume(double liters);

    virtual void Start();

    virtual void Stop();

    virtual bool getIsRunning();
    
};

#endif // ENGINE_H