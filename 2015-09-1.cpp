#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int before = -1;
    int now;
    int ans = 0;
    while (n--)
    {
        cin >> now;
        if (now != before)
        {
            before = now;
            ans++;
        }
    }
    cout << ans;
    return 0;
}