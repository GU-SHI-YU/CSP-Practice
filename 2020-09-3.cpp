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
map<string, int> gt;

int stringToI(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ans *= 10;
        ans += s[i] - '0';
    }
    return ans;
}

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
    int num;
    iss >> num;
    while (num--)
    {
        iss >> temp;
        int out = stringToI(temp.substr(1));
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
    gt["NOT"] = 1;
    gt["NAD"] = 2;
    gt["OR"] = 3;
    gt["XOR"] = 4;
    gt["NAND"] = 5;
    gt["NOR"] = 6;
    int Q;
    cin >> Q;
    while (Q--)
    {
        isLoop = false;
        cin >> m >> n;
        init();
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
                cin >> input[k][i];
            }
        }
        for (int k = 0; k < s; k++)
        {
            bool flag = false;
            do
            {
                flag = false;
                for (int i = 1; i <= n; i++)
                {
                    int old = output[k][i];
                    int a = 0;
                    bool temp;
                    int loc;
                    switch (gt[gates[i].type])
                    {
                    case 1:
                    {
                        loc = gates[i].inputs[0];
                        output[k][i] = loc > 0 ? !input[k][loc] : !output[k][-loc];
                        break;
                    }
                    case 2:
                    {
                        temp = true;
                        for (int j = 0; j < gates[i].inputs.size(); j++)
                        {
                            loc = gates[i].inputs[j];
                            temp &= loc > 0 ? input[k][loc] : output[k][-loc];
                        }
                        output[k][i] = temp;
                        break;
                    }
                    case 3:
                    {
                        temp = false;
                        for (int j = 0; j < gates[i].inputs.size(); j++)
                        {
                            loc = gates[i].inputs[j];
                            temp |= loc > 0 ? input[k][loc] : output[k][-loc];
                        }
                        output[k][i] = temp;
                        break;
                    }
                    case 4:
                    {
                        temp = false;
                        for (int j = 0; j < gates[i].inputs.size(); j++)
                        {
                            loc = gates[i].inputs[j];
                            temp ^= loc > 0 ? input[k][loc] : output[k][-loc];
                        }
                        output[k][i] = temp;
                        break;
                    }
                    case 5:
                    {
                        temp = true;
                        for (int j = 0; j < gates[i].inputs.size(); j++)
                        {
                            loc = gates[i].inputs[j];
                            temp &= loc > 0 ? input[k][loc] : output[k][-loc];
                        }
                        output[k][i] = !temp;
                        break;
                    }
                    case 6:
                    {
                        temp = false;
                        for (int j = 0; j < gates[i].inputs.size(); j++)
                        {
                            loc = gates[i].inputs[j];
                            temp |= loc > 0 ? input[k][loc] : output[k][-loc];
                        }
                        output[k][i] = !temp;
                        break;
                    }
                    default:
                        break;
                    }
                    if (old != output[k][i])
                        flag = true;
                }
            } while (flag);
            int si;
            cin >> si;
            for (int i = 0; i < si; i++)
            {
                int check;
                cin >> check;
                cout << (output[k][check] ? 1 : 0) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}