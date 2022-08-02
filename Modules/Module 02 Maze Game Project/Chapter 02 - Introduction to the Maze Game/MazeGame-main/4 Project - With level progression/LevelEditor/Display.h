#pragma once
#include <vector>
#include <string>

class Display
{
public:
	void DisplayLegend();
	void DisplayList(std::vector<std::string> options);
	void DisplayLevel(char* pLevel, int width, int height, int cursorX, int cursorY);
	void DisplayTopBorder(int width);
	void DisplayBottomBorder(int width);
	void DisplayLeftBorder();
	void DisplayRightBorder();
};

