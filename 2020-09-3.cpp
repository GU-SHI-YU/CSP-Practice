#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Gate
{
    string type;
    vector<int> inputs;
};

Gate gates[505];
bool input[10000][2505];
bool output[10000][505];
int f[505];
int n, m;
bool isLoop;
map<string, int> gt = {{"NOT", 1}, {"AND", 2}, {"OR", 3}, {"XOR", 4}, {"NAND", 5}, {"NOR", 6}};

void init()
{
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
}

int find(int x)
{
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        f[fx] = fy;
    }
    else
        isLoop = true;
}

void inputString(Gate &g, int i)
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    iss >> g.type;
    string temp;
    while (iss >> temp)
    {
        int out = stoi(temp.substr(1));
        if (temp[0] == 'I')
        {
            g.inputs.push_back(out);
        }
        else
        {
            g.inputs.push_back(-out);
            merge(i, out);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q--)
    {
        init();
        isLoop = false;
        cin >> m >> n;
        cin.get();
        for (int i = 1; i <= n; i++)
        {
            inputString(gates[i], i);
        }
        if (isLoop)
        {
            cout << "LOOP" << endl;
            int s;
            cin >> s;
            s += s;
            cin.get();
            string trash;
            while (s--)
            {
                getline(cin, trash);
            }
            continue;
        }
        int s;
        cin >> s;
        for (int k = 0; k < s; k++)
        {
            for (int i = 1; i <= m; i++)
            {
                cin >> input[s][i];
            }
        }
        for (int k = 0; k < s; k++)
        {
            bool flag = false;
            do
            {
                for (int i = 1; i <= n; i++)
                {
                    int old = output[s][i];
                    int a = 0;
                    bool temp;
                    int loc;
                    switch (gt[gates[i].type])
                    {
                    case 1:
                        loc = gates[i].inputs[0];
                        output[s][i] = loc > 0 ? !input[s][loc] : !output[s][-loc];
                        break;
                    case 2:
                        temp = true;
                        while (a < gates[i].inputs.size())
                        {
                            loc = gates[i].inputs[a];
                            temp &= loc > 0 ? !input[s][loc] : !output[s][-loc];
                        }
                        output[s][i] = temp;
                        break;
                    case 3:
                        temp = false;
                        while (a < gates[i].inputs.size())
                        {
                            loc = gates[i].inputs[a];
                            temp |= loc > 0 ? !input[s][loc] : !output[s][-loc];
                        }
                        output[s][i] = temp;
                        break;
                    case 4:
                        temp = false;
                        while (a < gates[i].inputs.size())
                        {
                            loc = gates[i].inputs[a];
                            temp ^= loc > 0 ? !input[s][loc] : !output[s][-loc];
                        }
                        output[s][i] = temp;
                        break;
                    case 5:
                        temp = true;
                        while (a < gates[i].inputs.size())
                        {
                            loc = gates[i].inputs[a];
                            temp &= loc > 0 ? !input[s][loc] : !output[s][-loc];
                        }
                        output[s][i] = !temp;
                        break;
                    case 6:
                        temp = false;
                        while (a < gates[i].inputs.size())
                        {
                            loc = gates[i].inputs[a];
                            temp |= loc > 0 ? !input[s][loc] : !output[s][-loc];
                        }
                        output[s][i] = !temp;
                        break;
                    default:
                        break;
                    }
                    if (old != output[s][i])
                        flag = true;
                }
            } while (flag);
            int si;
            cin >> si;
            for (int i = 0; i < si; i++)
            {
                int check;
                cin >> check;
                cout << (output[s][check] ? 1 : 0) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}