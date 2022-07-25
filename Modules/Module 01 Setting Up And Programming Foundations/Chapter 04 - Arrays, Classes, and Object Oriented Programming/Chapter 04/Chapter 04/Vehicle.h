#pragma once
#include <string.h>

class Vehicle
{
	int miles;
public:
	int Drive(int m) {
		miles += m;
		return miles;
	};
};	

