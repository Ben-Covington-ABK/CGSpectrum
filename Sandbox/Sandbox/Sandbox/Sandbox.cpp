// Sandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
template<typename... Arguments>
auto print(vector<Arguments>... args)
{
	constexpr auto numargs{ sizeof...(Arguments) };
	for( auto arg : ...args)
	{
		cout << arg;
	}
	return args;
	//X xobj[numargs]; // array of some previously defined type X

	//helper_func(xobj, args...);
}
*/

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

int main()
{
	tprintf("% world% %\n", "Hello", '!', 123);
	cout << endl;
	for(int i = 1; i <= 256; i++)
	{
		cout << i << ":" << (char)i << "\t";
		if(i % 8 == 0)
		{
			cout << "\n";
		}
	}
}
