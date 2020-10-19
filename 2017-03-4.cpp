#include <iostream>
#include <queue>

using namespace std;

struct Edge
{
    int time;
    int src;
    int dest;

    Edge(int _time, int _src, int _dest) : time(_time), src(_src), dest(_dest){};
    bool operator<(const Edge &e) const
    {
        return e.time < time;
    }
};

priority_queue<Edge> edges;
int f[100005];
int ans = INT_MIN;

int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b, time;
        cin >> a >> b >> time;
        edges.push(Edge(time, a, b));
    }
    for (int i = 1; i <= n; i++)
        f[i] = i;
    while (find(1) != find(n))
    {
        Edge e = edges.top();
        edges.pop();
        int fa, fb;
        fa = find(e.src), fb = find(e.dest);
        if (fa != fb)
        {
            f[fa] = fb;
            ans = max(ans, e.time);
        }
    }
    cout << ans << endl;
    return 0;
}