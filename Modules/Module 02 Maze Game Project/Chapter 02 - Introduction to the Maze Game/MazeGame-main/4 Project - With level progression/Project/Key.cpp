#include <iostream>
#include <windows.h>

#include "Key.h"

void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	//std::cout << "+";
	std::cout << (char)5;
	
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}
