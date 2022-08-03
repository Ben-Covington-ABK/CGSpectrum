// Pathfinder.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <map>

using namespace std;

auto add(vector<tuple<char, char, int>>& g, char x, char y, int z)
{
	g.push_back(tuple<char, char, int>{x, y, z});
}


/*
auto reconstruct_path(map<char, int> cameFrom, char current, set<char> keys)
{
	vector<tuple<char, int>> total_path{tuple<char, int>{current, 0}};
	while(keys.count(current))
	{
		current = cameFrom[current];
		total_path.push_back(current);
	}
	return total_path;
}
*/

/*
auto A_Star(char start, char goal, int h = 0)
{
	set<char> openSet { start };
	map<char, int> cameFrom;
	map<char, int> gScore;
	gScore[start] = 0;
	map<char, int> fScore;
	fScore[start] = h;
	while(!openSet.empty())
	{
		char current = start;
		if (current == goal) 
		{
			return reconstruct_path(cameFrom, current, openSet);
		}
		openSet.erase(current);
		
	}
}
*/

void printAll(vector<tuple<char, char, int>> graph)
{
	for (auto t : graph) 
	{
		cout << "(" 
			<< get<0>(t) << ", "
			<< get<1>(t) << ", " 
			<< get<2>(t) << ")\n";
	}
}

int main()
{
	vector<tuple<char, char, int>> graph;
	add(graph, 'a', 'b', 5);
	add(graph, 'b', 'c', 1);
	add(graph, 'a', 'd', 7);
	add(graph, 'c', 'd', 1);

	map<char, vector<tuple<char, int>>> groups;
	for(tuple<char, char, int> t : graph)
	{
		tuple<char, int> first{ get<1>(t), get<2>(t) };
		tuple<char, int> second{ get<0>(t), get<2>(t) };
		groups[get<0>(t)].push_back(first);
		groups[get<1>(t)].push_back(second);
	}

	for(auto &pair : groups)
	{
		cout << "{ " << pair.first << " : ";
		for(tuple<char, int> t : pair.second)
		{
			cout << "[" << get<0>(t) << ", "
				<< get<1>(t) << "], ";
		}
		cout << "}\n";
		/*
		cout << "{" << pair.first << ": [" 
			<< get<0>(pair.second) << "}\n";
		*/
	}

	//printAll(graph);
	/*
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
	*/
}
