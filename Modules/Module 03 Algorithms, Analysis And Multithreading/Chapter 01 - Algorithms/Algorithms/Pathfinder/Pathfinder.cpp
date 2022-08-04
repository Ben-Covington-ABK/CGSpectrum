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
typedef map<char, Neighbor> NeighborMap;
typedef map<char, vector<Neighbor>> NodeMap;
typedef map<char, int> ScoreMap;
typedef tuple<Steps, int> Path;

// Define enums for tuples
enum EDGE {first, second, length};
enum NEIGHBOR {next, cost};
enum PATH {steps, total};

// A* finds a path from start to goal.
// h is the heuristic defaulted to 0.
Path A_Star(NodeMap groups, char start, char goal, int h = 0)
{
	// The set of discovered nodes that may need to be (re-)expanded.
	// Initially, only the start node is know.
	Steps open{ start };
	
	// Path is a set of nodes and the total cost to travel the set.
	Path path{ open, 0 };

	// For node n, cameFrom[n] is the node immediately preceding it 
	// on the cheapest path frmo start to n currently known.
	NeighborMap cameFrom;

	// For node n, gScore[n] is the cost of the cheapest path from start.
	ScoreMap gScore;

	// For node n, fScore[n] is a guess of the cost of the cheapest path from start.
	ScoreMap fScore;

	// Default all node values to Infinity. (999 for simplicity)
	for (auto& pairs : groups)
	{
		char node = pairs.first;
		gScore[node] = node == start ? 0 : 999;
		fScore[node] = node == start ? h : 999;
	}

	while(!open.empty())
	{
		int currInt = -1;		// Current Index
		char current = NULL;	// Current Node

		// Linear search to find cheapest node in open.
		for (int i = 0; i < open.size(); i++)
		{
			if (current == NULL || fScore[open[i]] < fScore[current])
			{
				currInt = i;
				current = open[i];
			}
		}

		// When we find the goal fill and return the path.
		if (current == goal)
		{
			int total = get<NEIGHBOR::cost>(cameFrom[goal]);
			path = Path{ Steps{ goal }, total };
			while (cameFrom.count(current))
			{
				Neighbor neighbor = cameFrom[current];
				char next = get<NEIGHBOR::next>(neighbor);
				int cost = get<NEIGHBOR::cost>(neighbor);
				auto begin = get<PATH::steps>(path).begin();
				get<PATH::steps>(path).insert(begin, next);
				current = next;
			}
			return path;
		}

		// Remove the node at current index from open.
		open.erase(open.begin() + currInt);

		// For each neighbor of the current node. 
		for(Neighbor neighbor : groups[current])
		{
			char next = get<NEIGHBOR::next>(neighbor);	// Neighbor Node 
			int cost = get<NEIGHBOR::cost>(neighbor);	// Neighbor Length

			// tentative is the distance from start to the neighbor through current.
			int tentative = gScore[current] + cost;
			if (tentative < gScore[next])
			{
				// Record the path to neighbor as it is better than any previous one.
				cameFrom[next] = Neighbor{ current, tentative };
				gScore[next] = tentative;
				fScore[next] = tentative + h;

				// Add neighbor if they are not in open.
				if(!count(open.begin(), open.end(), next))
				{
					open.push_back(next);
				}
			}
		}
	}
	// Open set is empty but goal was never reached.
	return path;
}

void addNeighbor(NodeMap& groups, char node, Neighbor neighbor)
{
	if (groups[node].size() == 0) groups[node].push_back(neighbor);
	else
	{
		for (int i = 0; i < groups[node].size(); i++)
		{
			char next = get<NEIGHBOR::next>(groups[node][i]);
			int cost = get<NEIGHBOR::cost>(groups[node][i]);
			if (get<NEIGHBOR::cost>(neighbor) < cost) 
			{
				groups[node].insert(groups[node].begin() + i, neighbor);
				break;
			}
			else if (i >= groups[node].size() - 1)
			{
				groups[node].push_back(neighbor);
				break;
			}
		}
	}
}

NodeMap group(Graph graph)
{
	NodeMap groups;
	for (Edge edge : graph)
	{
		char x = get<EDGE::first>(edge);
		char y = get<EDGE::second>(edge);
		int len = get<EDGE::length>(edge);
		addNeighbor(groups, x, Neighbor{ y, len });
		addNeighbor(groups, y, Neighbor{ x, len });
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
			<< get<EDGE::length>(edge) << ")\n";
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
	graph.push_back(Edge{ 'd', 'e', 1 });
	graph.push_back(Edge{ 'b', 'e', 1 });

	printGraph(graph);
	cout << endl;
	
	NodeMap groups = group(graph);
	printGroups(groups);
	cout << endl;

	Path path = A_Star(groups, 'a', 'e');
	printPath(path);
	cout << endl;

	return 0;
}
