#include <iostream>

using namespace std;

bool a[105][105];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                a[i][j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (a[i][j])
                ans++;
        }
    }
    cout << ans;
    return 0;
}