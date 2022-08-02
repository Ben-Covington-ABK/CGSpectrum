#pragma once
class Level
{
public:
	void SaveLevel(char* pLevel, int width, int height);
	bool EditLevel(char* pLevel, int& cursorX, int& cursorY, int width, int height);
	void GetLevelDimensions(int& width, int& height);
};

