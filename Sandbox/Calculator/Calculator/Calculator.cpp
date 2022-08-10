// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <map>

using namespace std;

map<char, int(*)(int, int)> $;

int main()
{
	$['+'] = [](int a, int b) { return a + b; };
	$['-'] = [](int a, int b) { return a - b; };
	$['*'] = [](int a, int b) { return a * b; };
	$['/'] = [](int a, int b) { return a / b; };
	
	cout << $['+'](1, $['*'](2, 3));


}