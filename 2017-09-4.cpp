#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> g[1005];
bool visit[1005];
int ans = 0;
bool know[1005][1005];
int n, m;

void dfs(int v, int u)
{
    visit[v] = true;
    know[v][u] = know[u][v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (visit[g[v][i]] == false)
            dfs(g[v][i], u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(visit, false, sizeof(visit));
        dfs(i, i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        for (int j = 1; j <= n; j++)
        {
            if (know[i][j] == false)
                break;
            if (j == n)
                flag = true;
        }
        if (flag)
            ans++;
    }
    cout << ans << endl;
    return 0;
}