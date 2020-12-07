#include <algorithm>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

set<int> g[10005];
stack<int> path;
bool vis[10005][10005];
int n, m;
int f[10005];

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int v, int u)
{
    int fa = find(v);
    int fb = find(u);
    if (fa != fb)
    {
        f[fa] = fb;
    }
}

void dfs(int x)
{
    for (set<int>::iterator iter = g[x].begin(); iter != g[x].end(); iter++)
    {
        if (!vis[x][*iter])
        {
            vis[x][*iter] = true;
            vis[*iter][x] = true;
            dfs(*iter);
        }
    }
    path.push(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
        merge(a, b);
    }
    bool hasPath = true;
    int root = find(1);
    for (int i = 2; i <= n; i++)
    {
        if (find(i) != root)
        {
            hasPath = false;
            break;
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() % 2 == 1)
        {
            count++;
            if (count > 2)
            {
                hasPath = false;
                break;
            }
        }
    }
    if (!(count == 0 || (count == 2 && g[1].size() % 2 == 1)))
        hasPath = false;
    if (hasPath)
    {
        dfs(1);
        while (!path.empty())
        {
            int temp = path.top();
            path.pop();
            cout << temp << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}