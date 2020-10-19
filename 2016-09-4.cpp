#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int dist[10005];
int cost[10005];
bool visited[10005];
vector<vector<pair<int, int>>> g(10005);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void dijkstra()
{
    while (q.size() != 0)
    {
        pair<int, int> p = q.top();
        q.pop();
        int u = p.second;
        if (visited[u])
            continue;
        visited[u] = true;
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].second;
            int l = g[u][i].first;
            if (visited[v])
                continue;
            if (dist[u] + l < dist[v])
            {
                dist[v] = dist[u] + l;
                cost[v] = l;
                q.push(make_pair(dist[v], v));
            }
            else if (dist[u] + l == dist[v])
            {
                cost[v] = min(cost[v], l);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, value;
        cin >> a >> b >> value;
        g[a].push_back(make_pair(value, b));
        g[b].push_back(make_pair(value, a));
    }
    fill(dist + 1, dist + n + 1, INT_MAX);
    dist[1] = 0;
    cost[1] = 0;
    q.push(make_pair(dist[1], 1));
    dijkstra();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += cost[i];
    }
    cout << ans << endl;
    return 0;
}