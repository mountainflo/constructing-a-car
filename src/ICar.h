#ifndef I_CAR_H
#define I_CAR_H

class ICar
{
public:

    virtual void EngineStart() = 0;

    virtual void EngineStop() = 0;

    virtual void Refuel(double liters) = 0;

    virtual void RunningIdle() = 0;
};

#endif // I_CAR_H