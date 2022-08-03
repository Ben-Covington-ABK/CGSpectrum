// Pathfinder.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

// Define names for types
typedef vector<char> Steps;
typedef tuple<char, char, int> Edge;
typedef vector<Edge> Graph;
typedef tuple<char, int> Neighbor;
typedef map<char, vector<Neighbor>> NodeMap;
typedef tuple<Steps, int> Path;

// Define enums for tuples
enum EDGE {first, second, cost};
enum NEIGHBOR {next, cost};
enum PATH {steps, total};

Path A_Star(NodeMap groups, char start, char goal, int h = 0)
{
	Steps open{ start };
	Steps closed;
	Path path{ Steps{start}, 0 };
	while(!open.empty())
	{
		char current = open.back();
		if(current == goal)	return path;
		closed.push_back(current);
		open.pop_back();
		int offset = 999;
		for(Neighbor neighbor : groups[current])
		{
			char next = get<NEIGHBOR::next>(neighbor);
			if(!count(closed.begin(), closed.end(), next))
			{
				int cost = get<NEIGHBOR::cost>(neighbor);
				int total = get<PATH::total>(path);
				int newTotal = total + cost;
				int largest = total + offset;
				if (total == 0 || newTotal < largest)
				{
					offset = 0;
					get<PATH::steps>(path).push_back(next);
					get<PATH::total>(path) = newTotal;
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
	for (Edge edge : graph)
	{
		Neighbor first{ get<EDGE::second>(edge), get<EDGE::cost>(edge) };
		Neighbor second{ get<EDGE::first>(edge), get<EDGE::cost>(edge) };
		groups[get<EDGE::first>(edge)].push_back(first);
		groups[get<EDGE::second>(edge)].push_back(second);
	}
	return groups;
}

void printGraph(Graph graph)
{
	for (Edge edge : graph) 
	{
		cout << "(" 
			<< get<EDGE::first>(edge) << ", "
			<< get<EDGE::second>(edge) << ", " 
			<< get<EDGE::cost>(edge) << ")\n";
	}
}

void printGroups(NodeMap groups)
{
	for (auto& pair : groups)
	{
		cout << "{ " << pair.first << " : ";
		for (int i = 0; i < pair.second.size(); i++)
		{
			cout << "[" << get<NEIGHBOR::next>(pair.second[i])
				<< ", " << get<NEIGHBOR::cost>(pair.second[i]) << "]"
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
