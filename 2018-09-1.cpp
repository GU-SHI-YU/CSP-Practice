#include <iostream>

using namespace std;

int a[1005];
int ans[1005];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    for (int i = 0;i < n;i++)
    {
        if (i == 0)
        {
            ans[0] = (a[0] + a[1]) / 2;
        }
        else if (i == n - 1)
        {
            ans[n - 1] = (a[n - 1] + a[n - 2]) / 2;
        }
        else
            ans[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
    }
    for (int i = 0;i < n;i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}