#include <vector>
#include "Sort.h"

using namespace std;

vector<int> Sort::Bubble(vector<int> vec)
{
	vector<int> data = vec;
	// Loop to control the number of passes
	for(int num : data)
	{
		// Loop to control the number of comparisons per pass
		for (int i = 0; i < data.size() - 1; i++)
		{
			// Compare adjacent element values
			if(data[i] > data[i + 1])
			{
				// Store the current integer in a temp variable
				int temp = data[i];

				// Shift the next element to the current position
				data[i] = data[i + 1];

				// Assign the next value to the value held in temp
				data[i + 1] = temp;
			}
		}
	}
	return data;
}

int Extract(vector<int>& vec, int pos = 0)
{
	int val = vec[pos];
	vec.erase(vec.begin() + pos);
	return val;
}

vector<int> MergeSort(vector<int> left, vector<int> right)
{
	vector<int> results;
	bool toLeft = true;
	while(!left.empty() || !right.empty())
	{
		if(!left.empty() && !right.empty())
		{
			toLeft = left[0] <= right[0];
		}
		else if(!left.empty())
		{
			toLeft = true;
		}
		else if(!right.empty())
		{
			toLeft = false;
		}
		results.push_back(toLeft ? Extract(left, 0) : Extract(right, 0));
	}
	return results;
}

vector<int> Sort::Merge(vector<int> vec)
{
	if(vec.size() <= 1)	return vec;
	vector<int> left;
	vector<int> right;
	for(int i = 0; i < vec.size(); i++)
	{
		if(i < vec.size() / 2) left.push_back(vec[i]);
		else right.push_back(vec[i]);
	}
	left = Merge(left);
	right = Merge(right);
	return MergeSort(left, right);
}