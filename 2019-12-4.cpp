#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int n, m, k, t;
vector<vector<int>> G;
vector<vector<int>> links;
map<int, unordered_map<int, vector<int>>> rec;
map<int, unordered_map<int, vector<int>>> cre;

vector<int> input()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> res;
    int x = 0;
    while (iss >> x)
        res.push_back(x);
    return res;
}
void update(int time, int idx, const vector<int> &vec)
{
    auto &cur = links[idx];
    if (cur.size() < vec.size() || cur.size() == vec.size() && cur.back() > vec.back())
    {
        cur = vec;
        for (int nei : G[idx])
        {
            auto &temp = rec[time + t][nei];
            if (temp.size() < cur.size() || temp.size() == cur.size() && temp.back() > cur.back())
                temp = cur;
        }
    }
}

void processUntil(int T)
{
    auto rec_p = rec.begin();
    auto cre_p = cre.begin();
    while (rec_p != rec.end() || cre_p != cre.end())
    {
        if (cre_p == cre.end() || rec_p != rec.end() && rec_p->first <= cre_p->first)
        {
            if (rec_p->first > T)
                break;
            for (const auto &ele : rec_p->second)
            {
                update(rec_p->first, ele.first, ele.second);
            }
            rec_p = rec.erase(rec_p);
        }
        else
        {
            if (cre_p->first > T)
                break;
            for (const auto &ele : cre_p->second)
            {
                auto temp = links[ele.first];
                temp.insert(temp.end(), ele.second.begin(), ele.second.end());
                update(cre_p->first, ele.first, temp);
            }
            cre_p = cre.erase(cre_p);
            rec_p = rec.begin();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    G.resize(n + 1);
    links.resize(n + 1, {0});
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> t >> k;
    cin.get();
    while (k--)
    {
        vector<int> op = input();
        if (op.size() == 3)
        {
            cre[op[1]][op[0]].push_back(op[2]);
        }
        else
        {
            processUntil(op[1]);
            cout << links[op[0]].size();
            for (int x : links[op[0]])
                cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}