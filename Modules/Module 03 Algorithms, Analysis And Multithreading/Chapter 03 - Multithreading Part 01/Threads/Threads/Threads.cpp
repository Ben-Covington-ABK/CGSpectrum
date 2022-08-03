// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <thread>

using namespace std;

void Task() 
{
    cout << "Hello World!\n";
}


int main()
{
    thread Thread1(Task);
    Thread1.join();
    return 0;
}
