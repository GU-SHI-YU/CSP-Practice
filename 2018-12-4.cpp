#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Line
{
    int begin, end;
    int value;

    Line(int _begin, int _end, int _value)
    {
        begin = _begin;
        end = _end;
        value = _value;
    }
};

int fa[50005];
vector<Line> G;
int ans;

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

bool cmp(Line a, Line b)
{
    return a.value < b.value;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    int root;
    cin >> n >> m >> root;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G.push_back(Line(a, b, c));
    }
    sort(G.begin(), G.end(), cmp);
    int count = 0;
    for (auto &g : G)
    {
        int a = g.begin;
        int b = g.end;
        if (find(a) != find(b))
        {
            merge(a, b);
            if (ans < g.value)
                ans = g.value;
            count++;
        }
    }
    cout << ans << endl;
    return 0;
}