#include <iostream>

using namespace std;

int cake[1005];

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> cake[i];
    }
    int ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++)
    {
        now += cake[i];
        if (now >= k)
        {
            ans++;
            now = 0;
        }
    }
    cout << ((now != 0) ? ans + 1 : ans) << endl;
    return 0;
}