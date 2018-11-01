#include "catch.h"
#include "../src/Car.cpp"

TEST_CASE("TestMotorOfNewCar", "[TestMotorOfNewCar]")
{
    
    Car car;
        
    REQUIRE(car.getEngineIsRunning() == false);

    car.EngineStart();
        
    REQUIRE(car.getEngineIsRunning() == true);

    car.EngineStop();

    REQUIRE(car.getEngineIsRunning() == false);

}

TEST_CASE("TestFuelTankDisplayOfNewCar", "[TestFuelTankDisplayOfNewCar]")
{
    
    Car car;
        
    REQUIRE(car.fuelTankDisplay->getIsComplete() == false);
        
    REQUIRE(car.fuelTankDisplay->getIsOnReserve() == false);

}

TEST_CASE("TestFuelConsumptionOnIdle", "[TestFuelConsumptionOnIdle]")
{
    
    Car car(1);
    
    car.EngineStart();
        
    for(int i = 0; i < 3000; i++) {
        car.RunningIdle();
    }
        
    REQUIRE(car.fuelTankDisplay->getFillLevel() == 0.10);
}

TEST_CASE("TestFuelTankDisplayIsComplete", "[TestFuelTankDisplayIsComplete]")
{
    
    Car car(60);
    
    REQUIRE(car.fuelTankDisplay->getIsComplete() == true);
}

TEST_CASE("TestFuelTankDisplayIsOnReserve", "[TestFuelTankDisplayIsOnReserve]")
{
    
    Car car(4);
    
    REQUIRE(car.fuelTankDisplay->getIsOnReserve() == true);
}

TEST_CASE("TestRefuel", "[TestRefuel]")
{
    
    Car car(5);

    car.Refuel(40);
    
    REQUIRE(car.fuelTankDisplay->getFillLevel() == 45);
}

TEST_CASE("TestMotorDoesntStartWithEmptyFuelTank", "[TestMotorDoesntStartWithEmptyFuelTank]")
{
    
    Car car(0);

    car.EngineStart();
    
    REQUIRE(car.getEngineIsRunning() == false);
}

TEST_CASE("TestNoConsumptionWhenEngineNotRunning", "[TestNoConsumptionWhenEngineNotRunning]")
{
    
    Car car;

    double startFillLevel = car.fuelTankDisplay->getFillLevel();

    for(int i = 0; i < 3000; i++) {
        car.RunningIdle();
    }
        
    REQUIRE(car.fuelTankDisplay->getFillLevel() == startFillLevel);
}

TEST_CASE("TestNoNegativeFuelLevelAllowed", "[TestNoNegativeFuelLevelAllowed]")
{
    
    Car car(-5);

    car.Refuel(-10);
    
    REQUIRE(car.fuelTankDisplay->getFillLevel() == 0);
}

TEST_CASE("TestEngineStopsCauseOfNoFuelExactly", "[TestEngineStopsCauseOfNoFuelExactly]")
{
    Car car(1);
    
    car.EngineStart();
        
    for(int i = 0; i < 3334; i++) {
        car.RunningIdle();
    }
        
    REQUIRE(car.getEngineIsRunning() == false);
}

TEST_CASE("TestEngineStopsCauseOfNoFuelOver", "[TestEngineStopsCauseOfNoFuelOver]")
{
    Car car(1);
    
    car.EngineStart();
        
    for(int i = 0; i < 3333; i++) {
        car.RunningIdle();
    }
        
    REQUIRE(car.getEngineIsRunning() == false);
}

TEST_CASE("TestFuelTankDisplayRoundFillLevel", "[TestFuelTankDisplayRoundFillLevel]")
{
    Car car(0);
    
    car.Refuel(0.999999);
        
    REQUIRE(car.fuelTankDisplay->getFillLevel() == 1);
}
