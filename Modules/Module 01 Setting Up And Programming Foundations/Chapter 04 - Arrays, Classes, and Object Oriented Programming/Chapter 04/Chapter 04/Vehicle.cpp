#include "Vehicle.h";

Vehicle::Vehicle()
{
	name = "Vehicle";
}

int Vehicle::Drive(int m)
{
	miles += m;
	return miles;
}