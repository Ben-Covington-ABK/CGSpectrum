// Sandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>
#include <map>

#define NAME(var) (#var)

using namespace std;

void tprintf(const char* format) // base function
{
	cout << format;
}

template<typename T, typename... Targs>
void tprintf(const char* format, T value, Targs... Fargs) // recursive variadic function
{
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			cout << value;
			tprintf(format + 1, Fargs...); // recursive call
			return;
		}
		cout << *format;
	}
}

void printChars()
{
	char t = 9, sc = 58, n = 10;
	for (int i = 1; i <= 256; i++)
	{
		cout << i << sc << (char)i
			<< (i % 8 == 0 ? n : t);
	}
}


int main()
{
	//tprintf("% world% %\n", "Hello", '!', 123);
	//printChars();

	void (*greet)() = []() 
	{
		cout << "Hello World!\n";
	};

	cout << typeid(greet).name() << endl;
	greet();

	vector<void (*)()> vec{ greet };

	//vec.push_back(((*greet));

	cout << typeid(vec[0]).name() << endl;
	vec[0]();


	map<string, void(*)()> utils;
	cout << "Name: " << NAME(greet) << endl;
	utils[NAME(greet)] = greet;
	utils[NAME(greet)]();

}
