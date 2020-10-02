#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    string t;
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 1 || i == 5 || i == 11)
            continue;
        t.push_back(s[i]);
    }
    int check = 0;
    for (int i = 0; i < 9; i++)
    {
        check += (t[i] - '0') * (i + 1);
    }
    if (check % 11 == 10 && t[9] == 'X')
        cout << "Right";
    else if (check % 11 == t[9] - '0')
        cout << "Right";
    else
    {
        t[9] = check % 11 == 10 ? 'X' : '0' + check % 11;
        cout << t[0] << '-' << t[1] << t[2] << t[3] << '-' << t[4] << t[5] << t[6] << t[7] << t[8] << '-' << t[9];
    }
    return 0;
}