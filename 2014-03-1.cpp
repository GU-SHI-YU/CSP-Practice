#include <iostream>

using namespace std;

int a[505];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if ((a[i] + a[j]) == 0)
                ans++;
        }
    }
    cout << ans;
    return 0;
}