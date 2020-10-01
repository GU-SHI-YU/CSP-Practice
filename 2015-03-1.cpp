#include <iostream>

using namespace std;

int g[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[j][m - i - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}