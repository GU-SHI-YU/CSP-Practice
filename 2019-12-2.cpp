#include <iostream>
#include <set>

using namespace std;

int x[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int y[8] = {1, -1, 0, 0, 1, -1, 1, -1};

bool contain(set<pair<int, int>> g, pair<int, int> a)
{
    return g.find(a) != g.end();
}

bool check(set<pair<int, int>> g, pair<int, int> a)
{
    bool flag = true;
    for (int i = 0; i < 4; i++)
    {
        pair<int, int> temp = make_pair(a.first + x[i], a.second + y[i]);
        if (!contain(g, temp))
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int scoring(set<pair<int, int>> g, pair<int, int> a)
{
    int score = 0;
    for (int i = 4; i < 8; i++)
    {
        pair<int, int> temp = make_pair(a.first + x[i], a.second + y[i]);
        if (contain(g, temp))
        {
            score++;
        }
    }
    return score;
}

int main()
{
    ios::sync_with_stdio(false);
    set<pair<int, int>> g;
    int n;
    int ans[5] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        g.insert(temp);
    }
    for (auto p : g)
    {
        if (check(g, p))
            ans[scoring(g, p)]++;
    }
    for (int i = 0; i < 5; i++)
        cout << ans[i] << endl;
    return 0;
}