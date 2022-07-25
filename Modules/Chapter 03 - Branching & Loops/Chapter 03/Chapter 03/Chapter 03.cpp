#include <iostream>
#include <string>

using namespace std;

int Input()
{
    cout << "1. Leap Year Calc" << endl
        << "2. Find Factors" << endl
        << "3. Exit" << endl;
    int input;
    cin >> input;
    return input;
}

bool IsLeapYear()
{
    cout << "Enter a year" << endl;
    int year;
    cin >> year;
    if(year % 400 == 0)
    {
        return true;
    } 
    else if (year % 100 == 0)
    {
        return false;
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string FindFactors()
{
    string factors;
    int number;
    cout << "Please enter a number" << endl;
    cin >> number;
    for(int i = 1; i <= number; i++)
    {
        factors += (number % i == 0) ? to_string(i) + " " : "";
    }
    return factors;
}

int main()
{
    bool active = true;
    int input;
    string isLY;
    while (active)
    {
        input = Input();
        system("cls");
        switch (input)
        {
        case 1:
            isLY = IsLeapYear() ? "is" : "is not";
            cout << "Year " << isLY << " leap year." << endl;
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
