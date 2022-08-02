#include <iostream>
#include <vector>
#include <string>
#include "Display.h"

using namespace std;

constexpr char kCursor = '_';

constexpr char kTopRightBorder = (char)187;
constexpr char kTopLeftBorder = (char)201;
constexpr char kBottomRightBorder = (char)188;
constexpr char kBottomLeftBorder = (char)200;
constexpr char kHorizontalBorder = (char)205;
constexpr char kVerticalBorder = (char)186;

void Display::DisplayLegend()
{
	cout << "Arrows to move cursor" << endl;
	cout << "ESC to finish editing" << endl;
	cout << "+ | - for walls" << endl;
	cout << "@ for player start" << endl;
	cout << "r g b for key" << endl;
	cout << "R G B for door" << endl;
	cout << "$ for money" << endl;
	cout << "l for extra life" << endl;
	cout << "v for vertical moving enemy" << endl;
	cout << "h for horizontal moving enemy" << endl;
	cout << "e for non-moving enemy" << endl;
	cout << "X for end" << endl;
}

void Display::DisplayList(vector<string> options)
{
	for (string& option : options)
	{
		cout << &option - &options[0] + 1
			<< ". " << option << endl;
	}
}

void Display::DisplayLevel(char* pLevel, int width, int height, int cursorX, int cursorY)
{
	DisplayTopBorder(width);

	for (int y = 0; y < height; y++)
	{
		DisplayLeftBorder();
		for (int x = 0; x < width; x++)
		{
			if (cursorX == x && cursorY == y)
			{
				cout << kCursor;
			}
			else
			{
				//int index = GetIndexFromXY(x, y, width);
				int index = x + y * width;
				cout << pLevel[index];
			}
		}
		DisplayRightBorder();
	}

	DisplayBottomBorder(width);
}

void Display::DisplayTopBorder(int width)
{
	cout << kTopLeftBorder;
	for (int i = 0; i < width; i++)
	{
		cout << kHorizontalBorder;
	}
	cout << kTopRightBorder << endl;
}

void Display::DisplayBottomBorder(int width)
{
	cout << kBottomLeftBorder;
	for (int i = 0; i < width; i++)
	{
		cout << kHorizontalBorder;
	}
	cout << kBottomRightBorder << endl;
}

void Display::DisplayLeftBorder()
{
	cout << kVerticalBorder;
}

void Display::DisplayRightBorder()
{
	cout << kVerticalBorder << endl;
}