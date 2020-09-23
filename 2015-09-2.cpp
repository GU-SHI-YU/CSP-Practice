#include <iostream>

using namespace std;

int monthDay[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main()
{
    ios::sync_with_stdio(false);
    int year, days;
    cin >> year >> days;
    int flag = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    for (int i = 0; i < 12; i++)
    {
        if (days - monthDay[flag][i] <= 0)
        {
            cout << i + 1 << endl;
            cout << days << endl;
            return 0;
        }
        else
            days -= monthDay[flag][i];
    }
    return 0;
}