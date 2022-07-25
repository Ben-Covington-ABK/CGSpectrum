#pragma once
#include <string>

class Vehicle
{
	int miles = 0;
public:
	std::string name;
	Vehicle();
	int Drive(int m);
};	

