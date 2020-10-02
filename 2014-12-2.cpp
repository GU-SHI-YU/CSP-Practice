#include <iostream>

using namespace std;

int a[505][505];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for (int k = 0; k < 2 * n - 1; k++)
    {
        if (k % 2 == 0)
        {
            for (int j = 0; j <= k; j++)
            {
                if (k - j > n - 1 || j > n - 1)
                    continue;
                cout << a[k - j][j] << " ";
            }
        }
        else
        {
            for (int i = 0; i <= k; i++)
            {
                if (k - i > n - 1 || i > n - 1)
                    continue;
                cout << a[i][k - i] << " ";
            }
        }
    }
    return 0;
}