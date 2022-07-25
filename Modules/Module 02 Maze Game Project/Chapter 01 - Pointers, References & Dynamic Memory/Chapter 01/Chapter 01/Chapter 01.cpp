// Chapter 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

using namespace std;

int Input()
{
	int input;
	bool valid = false;
	while (!valid) 
	{
		cout << "Please enter an integer." << endl;
		cin >> input;
		system("cls");
		valid = !cin.fail();
		if(!valid)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}		
	}
	return input;
}

int main()
{
	int a = Input();
	int b = Input();
	int* ptrA = &a;
	int* ptrB = &b;
	cout << "Value A: " << *ptrA << endl
		<< "Value B: " << *ptrB << endl;
	ptrA, ptrB = nullptr;
}