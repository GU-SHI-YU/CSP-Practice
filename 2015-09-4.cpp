#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const int maxn = 10005;
vector<int> g[maxn];
stack<int> s;
int dfs_clock, sccno[maxn], scc_no, pre[maxn], low[maxn];
void dfs(int u) //找强连通分量
{
    pre[u] = low[u] = ++dfs_clock;
    s.push(u);
    for (int i = 0; i < (int)g[u].size(); i++)
    {
        int v = g[u][i];
        if (!pre[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!sccno[v])
        {
            low[u] = min(low[u], pre[v]);
        }
    }
    if (pre[u] == low[u])
    {
        scc_no++;
        while (true)
        {
            int x = s.top();
            s.pop();
            sccno[x] = scc_no;
            if (x == u)
                break;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int src, dest;
    for (int i = 1; i <= m; i++)
    {
        cin >> src >> dest;
        g[src].push_back(dest);
    }
    memset(sccno, 0, sizeof(sccno));
    memset(pre, 0, sizeof(pre));
    memset(low, 0, sizeof(low));
    dfs_clock = 0, scc_no = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!pre[i])
            dfs(i);
    }
    int sum[maxn]; //每个强连通分量点的总数
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++)
    {
        sum[sccno[i]]++;
    }
    int city = 0; //便利城市对的总数
    for (int i = 1; i <= scc_no; i++)
    {
        city += (sum[i] - 1) * sum[i] / 2;
    }
    cout << city << endl;
}