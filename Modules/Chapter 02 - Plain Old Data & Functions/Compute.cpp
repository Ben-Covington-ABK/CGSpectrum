#include <iostream>
#include <math.h>

using namespace std;

int InputFunc()
{
    // Prompt user for function selection
    cout << "Select a mode:" << endl
        << "1. Sum" << endl
        << "2. Average" << endl
        << "3. Cube" << endl
        << "4. Exit" << endl;

    // Store user selection
    int selection;
    cin >> selection;
    return (int)selection;
}

float InputNum()
{
    cout << "Enter A Number" << endl; 
    float temp;
    cin >> temp;
    return temp;
}

int Sum() 
{
    float sum;
    for(int i; i <= 3;)
    {
        float input = InputNum();
        if(input)
        {
            i++;
            sum += input;
        }
        continue;
    }
    return round(sum);
}

int Average()
{
    int sum = Sum();
    return round(sum / 3);
}

int Cube()
{
    float input = InputNum();
    float cubed = input * input * input;
    return round(cubed);
}

int Compute()
{
    bool stop = false;
    int selection = InputFunc();
    switch(selection) 
    {
        case 1:
            cout << Sum();
            break;
        case 2:
            cout << Average();
            break;
        case 3:
            cout << Cube();
            break;
        case 4:
        default:
            stop = true;
            break;
    }
    if(!stop)
    {
        Compute();
    }

}

int main() 
{
    Compute();
}