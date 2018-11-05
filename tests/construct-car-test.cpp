#include "catch.h"
#include "../library/Car.h"

// How to use the TESTCASE-Macro
// TESTCASE( <NAME>, [<TAGS>] )
TEST_CASE("TestMotorOfNewCar", "[simple]")
{
    
    Car car;
        
    REQUIRE(car.get_engine_is_running() == false);

    car.engine_start();
        
    REQUIRE(car.get_engine_is_running() == true);

    car.engine_stop();

    REQUIRE(car.get_engine_is_running() == false);

}

TEST_CASE("TestFuelTankDisplayOfNewCar", "[simple]")
{
    
    Car car;
        
    REQUIRE(car.fuel_tank_display.get_is_complete() == false);
        
    REQUIRE(car.fuel_tank_display.get_is_on_reserve() == false);

}

TEST_CASE("TestFuelConsumptionOnIdle", "[simple]")
{
    
    Car car(1);
    
    car.engine_start();
        
    for(int i = 0; i < 3000; i++) {
        car.running_idle();
    }
        
    REQUIRE(car.fuel_tank_display.get_fill_level() == 0.10);
}

TEST_CASE("TestFuelTankDisplayIsComplete", "[simple]")
{
    
    Car car(60);
    
    REQUIRE(car.fuel_tank_display.get_is_complete() == true);
}

TEST_CASE("TestFuelTankDisplayIsOnReserve", "[simple]")
{
    
    Car car(4);
    
    REQUIRE(car.fuel_tank_display.get_is_on_reserve() == true);
}

TEST_CASE("TestRefuel", "[TestRefuel]")
{
    
    Car car(5);

    car.refuel(40);
    
    REQUIRE(car.fuel_tank_display.get_fill_level() == 45);
}

TEST_CASE("TestMotorDoesntStartWithEmptyFuelTank", "[simple]")
{
    
    Car car(0);

    car.engine_start();
    
    REQUIRE(car.get_engine_is_running() == false);
}

TEST_CASE("TestNoConsumptionWhenEngineNotRunning", "[simple]")
{
    
    Car car;

    double startFillLevel = car.fuel_tank_display.get_fill_level();

    for(int i = 0; i < 3000; i++) {
        car.running_idle();
    }
        
    REQUIRE(car.fuel_tank_display.get_fill_level() == startFillLevel);
}

TEST_CASE("TestNoNegativeFuelLevelAllowed", "[simple]")
{
    
    Car car(-5);

    car.refuel(-10);
    
    REQUIRE(car.fuel_tank_display.get_fill_level() == 0);
}

TEST_CASE("TestEngineStopsCauseOfNoFuelExactly", "[simple]")
{
    Car car(1);
    
    car.engine_start();
        
    for(int i = 0; i < 3334; i++) {
        car.running_idle();
    }
        
    REQUIRE(car.get_engine_is_running() == false);
}

TEST_CASE("TestEngineStopsCauseOfNoFuelOver", "[simple]")
{
    Car car(1);
    
    car.engine_start();
        
    for(int i = 0; i < 3333; i++) {
        car.running_idle();
    }
        
    REQUIRE(car.get_engine_is_running() == false);
}

TEST_CASE("TestFuelTankDisplayRoundFillLevel", "[simple]")
{
    Car car(0);
    
    car.refuel(0.999999);
        
    REQUIRE(car.fuel_tank_display.get_fill_level() == 1);
}
