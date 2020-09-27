#include <iostream>

using namespace std;

int table[35][35];
bool deleted[35][35];

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i - 1 >= 0 && i + 1 < n && table[i][j] == table[i + 1][j] && table[i - 1][j] == table[i][j])
            {
                deleted[i - 1][j] = deleted[i][j] = deleted[i + 1][j] = true;
            }
            if (j - 1 >= 0 && j + 1 < m && table[i][j - 1] == table[i][j] && table[i][j + 1] == table[i][j])
            {
                deleted[i][j - 1] = deleted[i][j] = deleted[i][j + 1] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (deleted[i][j])
                table[i][j] = 0;
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}