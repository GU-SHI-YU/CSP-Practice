#include <iostream>

using namespace std;

int n;
int first[305];
int second[305];
bool visit[305][205][305];

bool dfs(int d, int val)
{
    if (visit[d][val][first[d - 1]])
        return false;
    visit[d][val][first[d - 1]] = true;
    if (val <= 0)
        return false;
    first[d] = val;
    if (d == 1)
    {
        int temp = second[1] * 2;
        return dfs(2, temp - first[1]) || dfs(2, temp - first[1] + 1);
    }
    else if (d <= n)
    {
        int temp = second[d] * 3;
        return dfs(d + 1, temp - first[d - 1] - first[d]) ||
               dfs(d + 1, temp - first[d - 1] - first[d] + 1) ||
               dfs(d + 1, temp - first[d - 1] - first[d] + 2);
    }
    else
        return (first[n - 1] + first[n]) / 2 == second[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> second[i];
    for (int i = 1; i <= second[1] * 2; i++)
    {
        bool flag = dfs(1, i);
        if (flag)
            break;
    }
    for (int i = 1; i <= n; i++)
        cout << first[i] << " ";
    return 0;
}