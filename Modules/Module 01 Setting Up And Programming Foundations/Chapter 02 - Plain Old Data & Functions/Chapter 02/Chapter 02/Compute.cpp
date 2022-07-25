#include <iostream>

using namespace std;

int GetNum()
{
    int number;
    bool valid = false;
    while (!valid)
    {
        cout << "Please enter a number" << endl;
        cin >> number;
        valid = !cin.fail();
        system("cls");
        if (!valid)
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Sorry that was not an number." << endl;
        }
    }
    return number;
}

int Sum()
{
    return (GetNum() + GetNum() + GetNum());
}

int Average()
{
    int sum = Sum();
    return round(sum / 3);
}

int Cube()
{
    int num = GetNum();
    return (num * num * num);
}

int main()
{
    bool active = true;
    int selection;
    while (active)
    {
        cout << "Select a mode:" << endl
            << "1. Sum" << endl
            << "2. Average" << endl
            << "3. Cube" << endl
            << "4. Exit" << endl;
        selection = GetNum();
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