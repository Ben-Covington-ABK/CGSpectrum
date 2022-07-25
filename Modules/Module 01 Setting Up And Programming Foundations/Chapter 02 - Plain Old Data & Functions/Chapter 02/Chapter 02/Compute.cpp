#include <iostream>
#include <math.h>

using namespace std;

int Input()
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

float GetNum()
{
    cout << "Enter A Number" << endl;
    float temp;
    cin >> temp;
    system("cls");
    return temp;
}

int Sum()
{
    float sum = 0.0f;
    for (int i = 0; i < 3;)
    {
        float input = GetNum();
        if (input)
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
    float input = GetNum();
    float cubed = input * input * input;
    return round(cubed);
}

int main()
{
    bool active = true;
    int selection;
    while (active)
    {
        selection = Input();
        system("cls");
        switch (selection)
        {
        case 1:
            cout << "The sum is: " << Sum() << endl;
            break;
        case 2:
            cout << "The average is: " << Average() << endl;
            break;
        case 3:
            cout << "The cube is: " << Cube() << endl;
            break;
        case 4:
        default:
            active = false;
            break;
        }
    }
    return 0;
}