#include <iostream>

using namespace std;

struct Window
{
    int x1, x2, y1, y2;
};

Window windows[15];
int a[2565][1445];

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 0; i < 2565; i++)
    {
        for (int j = 0; j < 1445; j++)
        {
            a[i][j] = -1;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> windows[i].x1 >> windows[i].y1 >> windows[i].x2 >> windows[i].y2;
        for (int j = windows[i].x1; j <= windows[i].x2; j++)
        {
            for (int k = windows[i].y1; k <= windows[i].y2; k++)
            {
                a[j][k] = i;
            }
        }
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (a[x][y] == -1)
        {
            cout << "IGNORED" << endl;
        }
        else
        {
            cout << a[x][y] + 1 << endl;
            int t = a[x][y];
            for (int i = windows[t].x1; i <= windows[t].x2; i++)
            {
                for (int j = windows[t].y1; j <= windows[t].y2; j++)
                {
                    a[i][j] = t;
                }
            }
        }
    }
    return 0;
}