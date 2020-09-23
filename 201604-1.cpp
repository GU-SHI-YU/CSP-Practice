#include <iostream>

using namespace std;

int a[1005];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n - 1; i++)
    {
        if ((a[i] - a[i - 1]) * (a[i + 1] - a[i]) < 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}