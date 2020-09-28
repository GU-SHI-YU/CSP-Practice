#include <algorithm>
#include <iostream>
#define INF 10e8

using namespace std;

int dist[305];

int main()
{
    ios::sync_with_stdio(false);
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
    {
        int tempx, tempy;
        cin >> tempx >> tempy;
        int distt = (tempx - x) * (tempx - x) + (tempy - y) * (tempy - y);
        dist[i] = distt;
    }
    for (int k = 0; k < 3; k++)
    {
        int min = INF;
        int pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] < min)
            {
                pos = i;
                min = dist[i];
            }
        }
        cout << pos + 1 << endl;
        dist[pos] = INF;
    }
    return 0;
}
