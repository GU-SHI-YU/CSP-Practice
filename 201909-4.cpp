#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

struct Good
{
    int type;
    int id;
    int score;

    Good(int _type, int _id, int _score)
    {
        type = _type;
        id = _id;
        score = _score;
    }

    bool operator<(const Good &a) const
    {
        if (score != a.score)
            return score > a.score;
        else if (type != a.type)
            return type < a.type;
        else
            return id < a.id;
    }
};

using namespace std;

int m, n, opnum;
set<Good> goods;
unordered_map<long long, set<Good>::iterator> um;
vector<int> ans[55];

int main()
{
    ios::sync_with_stdio(false);
    cin >> m >> n;
    while (n--)
    {
        int id, score;
        cin >> id >> score;
        for (int i = 0; i < m; i++)
        {
            long long a = i * 10e9 + id;
            um[a] = goods.insert(Good(i, id, score)).first;
        }
    }
    cin >> opnum;
    while (opnum--)
    {
        int op;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            int a1, b1, c1;
            cin >> a1 >> b1 >> c1;
            Good temp = Good(a1, b1, c1);
            long long x1 = a1 * 10e9 + b1;
            um[x1] = goods.insert(Good(a1, b1, c1)).first;
            break;
        }
        case 2:
        {
            int a2, b2;
            cin >> a2 >> b2;
            long long x2 = a2 * 10e9 + b2;
            goods.erase(um[x2]);
            um.erase(x2);
            break;
        }
        case 3:
        {
            int K;
            int *k = new int[m];
            cin >> K;
            for (int i = 0; i < m; i++)
            {
                cin >> k[i];
            }
            int count = 0;
            int loc = 0;
            for (auto &good : goods)
            {
                int t = good.type;
                if (ans[t].size() < k[t])
                {
                    ans[t].push_back(good.id);
                    if (--K == 0)
                        break;
                }
            }
            for (int i = 0; i < m; i++)
            {
                if (ans[i].size() == 0)
                    cout << -1 << endl;
                else
                {
                    for (int j = 0; j < ans[i].size(); j++)
                    {
                        cout << ans[i][j] << " ";
                    }
                    cout << endl;
                }
                ans[i].clear();
            }
            break;
        }
        }
    }
    return 0;
}