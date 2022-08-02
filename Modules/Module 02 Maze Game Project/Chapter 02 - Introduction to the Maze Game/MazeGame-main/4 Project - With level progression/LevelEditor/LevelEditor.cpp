#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include "Display.h"
#include "Level.h"
#include "Clear.h"

using namespace std;

void RunEditor(char* pLevel, int width, int height);
auto cls = Clear();
auto display = Display();
auto level = Level();


int main()
{
	int levelWidth, levelHeight, input;
	char* pLevel = nullptr;
	bool done = false;
	vector<string> files;
	vector<string> options{
		"Load Level",
		"New Level",
		"Quit"
	};
	while (!done)
	{
		cls.ClearScreen();
		cout << "Please select one of the following options:" << endl;
		display.DisplayList(options);
		cin >> input;
		cls.ClearScreen();
		switch (input) 
		{
		case 1: // Load Level
		{
			int count = 0;
			string path = "../";
			cout << "Please select a file." << endl;
			for (const auto& entry :
				std::filesystem::directory_iterator(path))
			{
				string ext = entry.path().extension().string();
				if (ext == ".txt")
				{
					files.push_back(entry.path().string());
					cout << ++count << ". "
						<< entry.path() << endl;
				}
			}
			cin >> input;
			cls.ClearScreen();
			ifstream levelFile;
			string filePath = files.at(input - 1);
			levelFile.open(filePath);
			if (!levelFile)
			{
				cout << "Opening file failed!" << endl;
			}
			else
			{
				constexpr int tempSize = 25;
				char temp[tempSize];

				levelFile.getline(temp, tempSize, '\n');
				levelWidth = atoi(temp);

				levelFile.getline(temp, tempSize, '\n');
				levelHeight = atoi(temp);

				pLevel = new char[levelWidth * levelHeight];
				levelFile.read(pLevel, levelWidth * levelHeight);
				levelFile.close();

				RunEditor(pLevel, levelWidth, levelHeight);

				delete[] pLevel;
				pLevel = nullptr;

			}
			break;
		}
		case 2: // New Level
		{
			level.GetLevelDimensions(levelWidth, levelHeight);
			pLevel = new char[levelWidth * levelHeight];
			for (int i = 0; i < levelWidth * levelHeight; i++)
			{
				pLevel[i] = ' ';
			}
			RunEditor(pLevel, levelWidth, levelHeight);
			delete[] pLevel;
			pLevel = nullptr;
			break;
		}
		case 3: // Quit
		default:
		{
			done = true;
			break;
		}
		}

		/*
		
		if (input == 1)
		{
			int count = 0;
			string path = "../";
			cout << "Please select a file." << endl;
			for (const auto& entry : 
				std::filesystem::directory_iterator(path))
			{
				string ext = entry.path().extension().string();
				if(ext == ".txt")
				{
					files.push_back(entry.path().string());
					cout << ++count << ". " 
						<< entry.path() << endl;
				}
			}
			cin >> input;
			cls.ClearScreen();
			ifstream levelFile;
			string filePath = files.at(input-1);
			levelFile.open(filePath);
			if (!levelFile)
			{
				cout << "Opening file failed!" << endl;
			}
			else
			{
				constexpr int tempSize = 25;
				char temp[tempSize];

				levelFile.getline(temp, tempSize, '\n');
				levelWidth = atoi(temp);

				levelFile.getline(temp, tempSize, '\n');
				levelHeight = atoi(temp);

				pLevel = new char[levelWidth * levelHeight];
				levelFile.read(pLevel, levelWidth * levelHeight);
				levelFile.close();

				RunEditor(pLevel, levelWidth, levelHeight);

				delete[] pLevel;
				pLevel = nullptr;

			}

		}
		else if (input == 2)
		{
			// New Level
			level.GetLevelDimensions(levelWidth, levelHeight);

			pLevel = new char[levelWidth * levelHeight];

			for (int i = 0; i < levelWidth * levelHeight; i++)
			{
				pLevel[i] = ' ';
			}

			RunEditor(pLevel, levelWidth, levelHeight);

			delete[] pLevel;
			pLevel = nullptr;
		}
		else
		{
			done = true;
		}
		*/

	}

}

void RunEditor(char* pLevel, int width, int height)
{
	int cursorX = 0, cursorY = 0;
	bool doneEditing = false;
	while (!doneEditing)
	{
		cls.ClearScreen();
		display.DisplayLevel(pLevel, width, height, cursorX, cursorY);
		display.DisplayLegend();
		doneEditing = level.EditLevel(pLevel, cursorX, cursorY, width, height);
	}
	cls.ClearScreen();
	display.DisplayLevel(pLevel, width, height, -1, -1);
	level.SaveLevel(pLevel, width, height);
}