#include <iostream>
#include <string>

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

int Input()
{
    cout << "1. Leap Year Calc" << endl
        << "2. Find Factors" << endl
        << "3. Exit" << endl;
    return GetNum();
}

bool IsLeapYear()
{
    cout << "Enter a year" << endl;
    int year = GetNum();
    return year % 400 == 0
        ? true : year % 100 == 0
        ? false : year % 4 == 0;
}

string FindFactors()
{
    string factors;
    int number = GetNum();
    for(int i = 1; i <= number; i++)
    {
        factors += (number % i == 0) 
            ? to_string(i) + " " : "";
    }
    return factors;
}

int main()
{
    int input;
    bool active = true;
    while (active)
    {
        input = Input();
        switch (input)
        {
        case 1:
            cout << "Year " << (IsLeapYear() ? "is" : "is not") 
                << " leap year." << endl;
            break;
        case 2:
            cout << "Number has factors: " << FindFactors() << endl;
            break;
        case 3:
        default:
            active = false;
            break;
        }
    }
    return 0;
}
