#include <algorithm>
#include <iostream>

using namespace std;

int a[1005];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] == 1)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}