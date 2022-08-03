// Pathfinder.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

auto A_Star(map<char, vector<tuple<char, int>>> groups, char start, char goal, int h = 0)
{
	vector<char> open{ start };
	vector<char> closed;
	tuple<vector<char>, int> path{ vector<char>{start}, 0 };
	while(!open.empty())
	{
		char current = open.back();
		if(current == goal)	return path;
		closed.push_back(current);
		open.pop_back();
		int offset = 999;
		for(auto neighbor : groups[current])
		{
			char next = get<0>(neighbor);
			if(!count(closed.begin(), closed.end(), next))
			{
				int cost = get<1>(neighbor);
				int total = get<1>(path);
				int newTotal = total + cost;
				int largest = total + offset;
				if (total == 0 || newTotal < largest)
				{
					offset = 0;
					get<0>(path).push_back(next);
					get<1>(path) = newTotal;
					if(!count(open.begin(), open.end(), next))
					{
						open.push_back(next);
					}
				}
			}
		}
	}
	return path;
}

void add(vector<tuple<char, char, int>>& g, char x, char y, int z)
{
	g.push_back(tuple<char, char, int>{x, y, z});
}

auto group(vector<tuple<char, char, int>> graph)
{
	map<char, vector<tuple<char, int>>> groups;
	for (tuple<char, char, int> t : graph)
	{
		tuple<char, int> first{ get<1>(t), get<2>(t) };
		tuple<char, int> second{ get<0>(t), get<2>(t) };
		groups[get<0>(t)].push_back(first);
		groups[get<1>(t)].push_back(second);
	}
	return groups;
}

void printGraph(vector<tuple<char, char, int>> graph)
{
	for (auto t : graph) 
	{
		cout << "(" 
			<< get<0>(t) << ", "
			<< get<1>(t) << ", " 
			<< get<2>(t) << ")\n";
	}
}

void printGroups(map<char, vector<tuple<char, int>>> groups)
{
	for (auto& pair : groups)
	{
		cout << "{ " << pair.first << " : ";
		for (int i = 0; i < pair.second.size(); i++)
		{
			cout << "[" << get<0>(pair.second[i])
				<< ", " << get<1>(pair.second[i]) << "]"
				<< (i < pair.second.size() - 1 ? ", " : " ");
		}
		cout << "}\n";
	}
}

void printPath(tuple<vector<char>, int> path) 
{
	int length = get<0>(path).size();
	cout << "Path from ";
	for(int i = 0; i < length; i++)
	{
		cout << get<0>(path)[i];
		if (i < length - 1)
		{
			cout << " to ";
		}
	}
	cout << " cost " << get<1>(path);
}

int main()
{
	vector<tuple<char, char, int>> graph;
	add(graph, 'a', 'b', 5);
	add(graph, 'b', 'c', 1);
	add(graph, 'a', 'd', 7);
	add(graph, 'c', 'd', 1);
	printGraph(graph);
	cout << endl;
	
	auto groups = group(graph);
	printGroups(groups);
	cout << endl;

	auto path = A_Star(groups, 'd', 'a');
	printPath(path);
	cout << endl;

	return 0;
}
