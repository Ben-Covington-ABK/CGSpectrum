// Pathfinder.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

typedef tuple<char, char, int> Edge;
typedef vector<Edge> Graph;
typedef tuple<char, int> Neighbor;
typedef map<char, vector<Neighbor>> NodeMap;
typedef tuple<vector<char>, int> Path;

Path A_Star(NodeMap groups, char start, char goal, int h = 0)
{
	vector<char> open{ start };
	vector<char> closed;
	Path path{ vector<char>{start}, 0 };
	while(!open.empty())
	{
		char current = open.back();
		if(current == goal)	return path;
		closed.push_back(current);
		open.pop_back();
		int offset = 999;
		for(Neighbor neighbor : groups[current])
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

NodeMap group(Graph graph)
{
	NodeMap groups;
	for (Edge t : graph)
	{
		Neighbor first{ get<1>(t), get<2>(t) };
		Neighbor second{ get<0>(t), get<2>(t) };
		groups[get<0>(t)].push_back(first);
		groups[get<1>(t)].push_back(second);
	}
	return groups;
}

void printGraph(Graph graph)
{
	for (Edge edge : graph) 
	{
		cout << "(" 
			<< get<0>(edge) << ", "
			<< get<1>(edge) << ", " 
			<< get<2>(edge) << ")\n";
	}
}

void printGroups(NodeMap groups)
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

void printPath(Path path) 
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
	Graph graph;
	graph.push_back(Edge{ 'a', 'b', 5 });
	graph.push_back(Edge{ 'b', 'c', 1 });
	graph.push_back(Edge{ 'a', 'd', 7 });
	graph.push_back(Edge{ 'c', 'd', 1 });

	printGraph(graph);
	cout << endl;
	
	NodeMap groups = group(graph);
	printGroups(groups);
	cout << endl;

	Path path = A_Star(groups, 'a', 'd');
	printPath(path);
	cout << endl;

	return 0;
}
