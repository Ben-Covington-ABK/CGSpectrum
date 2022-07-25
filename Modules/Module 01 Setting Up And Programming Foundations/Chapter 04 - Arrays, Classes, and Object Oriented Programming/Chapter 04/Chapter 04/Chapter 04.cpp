#include <iostream>
#include <vector>
#include "Vehicle.h"

using namespace std;

class Car : public Vehicle 
{
public: 
	Car()
	{
		name = "Car";
	}
};
class Boat : public Vehicle 
{
public:
	Boat()
	{
		name = "Boat";
	}
};
class Airplane : public Vehicle 
{
public:
	Airplane() 
	{ 
		name = "Airplane"; 
	}
};

int GetNum()
{
	int number;
	bool valid = false;
	while(!valid)
	{
		cout << "Please enter a number" << endl;
		cin >> number;
		valid = !cin.fail();
		system("cls");
		if (!valid)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Sorry that was not an number." << endl;
		}
	}
	
	return number;
}

int Input()
{
	cout << "1. Find largest in list" << endl
		<< "2. Test drive a vehicle" << endl
		<< "3. Exit" << endl;
	int input = GetNum();
	return input;
}

Vehicle TestDrive()
{
	cout << "1. Car" << endl
		<< "2. Boat" << endl
		<< "3. Airplane" << endl;
	int input = GetNum();
	Vehicle rental = Vehicle();
	switch (input)
	{
	case 1:
		// Make a car
		rental = Car();
		break;
	case 2:
		// Make a boat
		rental = Boat();
		break;
	case 3: 
		// Make a plane
		rental = Airplane();
		break;
	default:
		break;
	}
	return rental;
}

int GetLargest()
{
	vector<int> nums;
	cout << "How many numbers will there be?" << endl;
	int size = GetNum();
	int largest = -INFINITY;
	for (int i = 0; i < size; i++)
	{
		int num = GetNum();
		nums.push_back(num);
		largest = num > largest ? num : largest;
	}
	return largest;
}

int main()
{
	bool active = true;
	int miles;
	Vehicle rental;
	while (active)
	{
		int input = Input();
		switch (input)
		{
		case 1:
			cout << "The largest number is " 
				<< GetLargest() << endl;
			break;
		case 2:
			rental = TestDrive();
			cout << "How many miles to drive?" << endl;
			miles = GetNum();
			cout << "Traveled " << rental.Drive(miles)
				<< " miles in a " << rental.name << endl;
			break;
		case 3:
		default:
			active = false;
			break;
		}
	}
	return 0;
}