#ifndef I_ENGINE_H
#define I_ENGINE_H

class IEngine
{
public:

    virtual void Consume(double liters) = 0;

    virtual void Start() = 0;

    virtual void Stop() = 0;

protected:

    bool isRunning = false;
};

#endif // I_ENGINE_H