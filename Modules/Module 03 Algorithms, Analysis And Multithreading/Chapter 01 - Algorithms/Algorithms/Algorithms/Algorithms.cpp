// Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <chrono>
#include <iostream>
#include <vector>
#include "Sort.h"
#include "Search.h"

using namespace std;

// Function to fill vector with random numbers
vector<int> Fill(int size)
{
    vector<int> data;  
    for (int i = 0; i < size; i++)
    {
        // Fill with a random number 1-100
        data.push_back(rand() % size + 1);
    }
    return data;
}

int GetRandom(vector<int> vec)
{
    int RandomIndex = rand() % vec.size() + 1;
    return vec[RandomIndex];
}

void PrintAll(vector<int> vec)
{
    int count = 0;
    for (int num : vec) 
    {
        cout << ++count << ": " 
            << num << "  \t  ";
        if(count % 5 == 0)
        {
            cout << endl;
        }
    }
}

auto tick()
{
    using namespace chrono;
    auto now = system_clock::now().time_since_epoch();
    return static_cast<uint32_t>(duration_cast<nanoseconds>(now).count());
}

int main()
{
    Sort sort = Sort(); 
    Search search = Search();
    
    // Defines sample size
    const int SAMPLE_SIZE = 1000;
    
    // Seed the RNG
    srand(time(nullptr));

    // Create and fill a dataset with random numbers
    vector<int> Dataset = Fill(SAMPLE_SIZE);

    int val = GetRandom(Dataset);

    auto start = tick();
    int key = search.Linear(Dataset, val);
    auto end = tick();
    cout << "Linear search took: "
        << (end - start) << " nanosecons.\n";

    // Sort out dataset
    //Dataset = sort.Bubble(Dataset);


    PrintAll(Dataset);
    Dataset = sort.Merge(Dataset);
    PrintAll(Dataset);

    start = tick();
    key = search.Binary(Dataset, val);
    end = tick();
    cout << "Binary search took: "
        << (end - start) << " nanosecons.\n";

    cout << "\nValue: " << val 
        << " found at position " << key + 1;
}

