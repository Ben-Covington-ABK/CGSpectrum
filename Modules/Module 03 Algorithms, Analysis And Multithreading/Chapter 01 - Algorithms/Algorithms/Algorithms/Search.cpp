#include <vector>
#include "Search.h"

using namespace std;

int Search::Linear(vector<int> vec, int val)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if(val == vec[i])
		{
			return i;
		}
	}
	return vec.size();
}

int Search::Binary(vector<int> vec, int val)
{
	int low = 0;
	int high = vec.size();
	while(low <= high)
	{
		int middle = (low + high) / 2;
		if(val == vec[middle])
		{
			return middle;
		}
		else if(val < vec[middle])
		{
			high = middle - 1;
		}
		else 
		{
			low = middle + 1;
		}
	}
	return vec.size();
}