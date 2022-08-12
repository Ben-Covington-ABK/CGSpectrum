// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int(*)(int, int)> $;

int main()
{
	$['+'] = [](int a, int b) { return a + b; };
	$['-'] = [](int a, int b) { return a - b; };
	$['*'] = [](int a, int b) { return a * b; };
	$['/'] = [](int a, int b) { return a / b; };

	void(*var)() = []() {cout << "HI\n"; };
	
	var();
	var();

	cout << $['+'](1, $['*'](2, 3));


}