// Sandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>

using namespace std;

int main()
{
	for(int i = 1; i <= 256; i++)
	{
		cout << i << ":" << (char)i << "\t";
		if(i % 8 == 0)
		{
			cout << "\n";
		}
	}
}
