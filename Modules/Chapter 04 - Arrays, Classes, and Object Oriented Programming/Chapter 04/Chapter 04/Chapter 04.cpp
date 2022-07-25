#include <iostream>
#include <vector>
#include "Vehicle.h"

using namespace std;

class Car : public Vehicle {};
class Boat : public Vehicle {};
class Airplane : public Vehicle {};

int GetNum()
{
	cout << "Please enter a number" << endl;
	int number;
	cin >> number;
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
	system("cls");
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
	system("cls");
	for (int i = 0; i < size; i++)
	{
		int num = GetNum();
		system("cls");
		nums.push_back(num);
		largest = num > largest ? num : largest;
	}
	return largest;
}

int main()
{
	bool active = true;
	Vehicle rental;
	while (active)
	{
		int input = Input();
		system("cls");
		switch (input)
		{
		case 1:
			cout << "The largest number is " 
				<< GetLargest() << endl;
			break;
		case 2:
			rental = TestDrive();
			cout << "Traveled " << rental.Drive(10)
				<< " miles" << endl;
			break;
		case 3:
		default:
			active = false;
			break;
		}
	}
	return 0;
}