#include "catch.h"
#include "../src/Car.h"

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
        
    REQUIRE(car.fuel_tank_display.getIsComplete() == false);
        
    REQUIRE(car.fuel_tank_display.getIsOnReserve() == false);

}

TEST_CASE("TestFuelConsumptionOnIdle", "[TestFuelConsumptionOnIdle]")
{
    
    Car car(1);
    
    car.EngineStart();
        
    for(int i = 0; i < 3000; i++) {
        car.RunningIdle();
    }
        
    REQUIRE(car.fuel_tank_display.getFillLevel() == 0.10);
}

TEST_CASE("TestFuelTankDisplayIsComplete", "[TestFuelTankDisplayIsComplete]")
{
    
    Car car(60);
    
    REQUIRE(car.fuel_tank_display.getIsComplete() == true);
}

TEST_CASE("TestFuelTankDisplayIsOnReserve", "[TestFuelTankDisplayIsOnReserve]")
{
    
    Car car(4);
    
    REQUIRE(car.fuel_tank_display.getIsOnReserve() == true);
}

TEST_CASE("TestRefuel", "[TestRefuel]")
{
    
    Car car(5);

    car.Refuel(40);
    
    REQUIRE(car.fuel_tank_display.getFillLevel() == 45);
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

    double startFillLevel = car.fuel_tank_display.getFillLevel();

    for(int i = 0; i < 3000; i++) {
        car.RunningIdle();
    }
        
    REQUIRE(car.fuel_tank_display.getFillLevel() == startFillLevel);
}

TEST_CASE("TestNoNegativeFuelLevelAllowed", "[TestNoNegativeFuelLevelAllowed]")
{
    
    Car car(-5);

    car.Refuel(-10);
    
    REQUIRE(car.fuel_tank_display.getFillLevel() == 0);
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
        
    REQUIRE(car.fuel_tank_display.getFillLevel() == 1);
}
