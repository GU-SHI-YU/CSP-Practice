#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const int maxn = 505;
int MonthDay[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll big[maxn][maxn], small[maxn][maxn];
int vis_big[maxn], vis_small[maxn];
ll sr[maxn], br[maxn];
ll path[maxn]; //记录顶点v之前正在连续的小路
ll n, m;
ll Dijkstra(ll v0)
{
    for (ll i = 0; i < n; i++)
    {
        sr[i] = small[v0][i];
        br[i] = big[v0][i];
        if (sr[i] < INF)
        {
            path[i] = sr[i];
            sr[i] *= sr[i];
        }
        else
            path[i] = INF;
    }
    vis_small[v0] = vis_big[v0] = 1;
    while (1)
    {
        ll minn = INF, flag = 0, v = -1;
        for (ll j = 0; j < n; j++)
        {
            if (!vis_big[j] && br[j] < minn)
            {
                flag = 0;
                v = j;
                minn = br[j];
            }
            if (!vis_small[j] && sr[j] < minn)
            {
                flag = 1;
                v = j;
                minn = sr[j];
            }
        }
        if (v == -1)
            break;
        if (flag)
            vis_small[v] = 1;
        else
            vis_big[v] = 1;
        for (ll j = 0; j < n; j++)
        {
            if (!vis_small[j] && small[v][j] < INF)
            {
                if (flag)
                { //prev到v之间是small road
                    ll temp = sr[v] - path[v] * path[v] + (path[v] + small[v][j]) * (path[v] + small[v][j]);
                    if (sr[j] > temp || sr[j] == temp && path[j] > path[v] + small[v][j])
                    {
                        sr[j] = temp;
                        path[j] = path[v] + small[v][j];
                    }
                }
                else
                { //prev到v之间是big road
                    ll temp = br[v] + small[v][j] * small[v][j];
                    if (sr[j] > temp || sr[j] == temp && path[j] > small[v][j])
                    {
                        sr[j] = temp;
                        path[j] = small[v][j];
                    }
                }
            }
            if (!vis_big[j] && big[v][j] < INF)
            {
                if (flag)
                {
                    ll temp = sr[v] + big[v][j];
                    br[j] = min(temp, br[j]);
                }
                else
                {
                    ll temp = br[v] + big[v][j];
                    br[j] = min(temp, br[j]);
                }
            }
        }
    }
    return min(br[n - 1], sr[n - 1]);
}
int main()
{

    ll t, a, b, c;
    while (cin >> n >> m)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j <= i; j++)
            {
                big[i][j] = big[j][i] = INF;
                small[i][j] = small[j][i] = INF;
            }
        }
        memset(vis_big, 0, sizeof(vis_big));
        memset(vis_small, 0, sizeof(vis_small));
        for (int i = 0; i < m; i++)
        {
            cin >> t >> a >> b >> c;
            a--;
            b--;
            if (t == 1)
                small[a][b] = small[b][a] = min(c, small[a][b]);
            else
                big[a][b] = big[b][a] = min(c, big[a][b]);
        }
        cout << Dijkstra(0) << endl;
    }
    return 0;
}