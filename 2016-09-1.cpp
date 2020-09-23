#include <cmath>
#include <iostream>

using namespace std;

int a[1005];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int temp = abs(a[i + 1] - a[i]);
        if (ans < temp)
            ans = temp;
    }
    cout << ans;
    return 0;
}