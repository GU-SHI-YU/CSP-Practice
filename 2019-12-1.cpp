#include <iostream>

using namespace std;

bool check(int n)
{
    if (n % 7 == 0)
        return true;
    while (n != 0)
    {
        if (n % 10 == 7)
            return true;
        n /= 10;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int count[4] = {0};
    int j;
    int cur = 1;
    int n;
    j = 0;
    cin >> n;
    for (int i = 0; i < n;)
    {
        if (check(cur))
            count[j]++;
        else
            i++;
        j++;
        if (j == 4)
            j = 0;
        cur++;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << count[i] << endl;
    }
    return 0;
}