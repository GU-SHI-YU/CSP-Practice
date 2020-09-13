#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int ans = 0;
    int stack = 0;
    int temp;
    cin >> temp;
    if (temp == 1)
        ans += 1;
    else if (temp == 2)
    {
        stack++;
        ans += 2;
    }
    else
    {
        cout << ans;
        return 0;
    }
    while (cin >> temp)
    {
        if (temp == 1)
        {
            ans += 1;
            stack = 0;
        }
        else if (temp == 2)
        {
            if (stack == 0)
            {
                stack++;
                ans += 2;
            }
            else
            {
                ans += (stack + 1) * 2;
                stack++;
            }
        }
        else
        {
            cout << ans;
            return 0;
        }
    }

    return 0;
}