// Pathfinder.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int length = 10;
	int height = 5;
	string map = "";
	vector<int> pos{ 1, 1 };
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < length; x++)
		{
			if (pos[0] == x && pos[1] == y) 
			{
				map += "@";
			}
			else
			{
				map += "*";
			}
		}
		map += "\n";
	}
	cout << map << endl;
}
