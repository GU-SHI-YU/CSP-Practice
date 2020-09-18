#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<int, set<int>> ops;
map<int, int> keys;

int check(map<int, int> k, int key)
{
    for (auto iter = k.begin(); iter != k.end(); iter++)
    {
        if (iter->second == key)
            return iter->first;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        keys[i] = i;
    }
    while (k--)
    {
        int key, s, c;
        cin >> key >> s >> c;
        ops[s].insert(10000 + key);
        ops[s + c].insert(key);
    }
    for (auto &op : ops)
    {
        for (auto &s_op : op.second)
        {
            if (s_op > 10000)
            {
                keys[check(keys, s_op - 10000)] = 0;
            }
            else
            {
                keys[check(keys, 0)] = s_op;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << keys[i] << " ";
    return 0;
}