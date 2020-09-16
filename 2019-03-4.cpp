#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

queue<long long> q[10005];

queue<long long> input()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    queue<long long> res;
    string command;
    while (iss >> command)
    {
        if (command[0] == 'R')
            res.push(stoi(command.substr(1)) + 1);
        else
            res.push(-stoi(command.substr(1)) - 1);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int T, n;
    cin >> T >> n;
    cin.get();
    while (T--)
    {
        for (int i = 0; i < n; i++)
        {
            q[i] = input();
        }
        int flag = 0;
        while (1)
        {
            flag = 0;
            int fflag = 0;
            for (int i = 0; i < n; i++)
            {
                if (q[i].size() != 0)
                {
                    int cmd = q[i].front();
                    fflag = 1;
                    if (cmd < 0)
                    {
                        if (q[-cmd - 1].size() == 0)
                        {
                            flag = 0;
                            break;
                        }
                        else
                        {
                            if (q[-cmd - 1].front() == i + 1)
                            {
                                flag = 1;
                                q[i].pop();
                                q[-cmd - 1].pop();
                            }
                        }
                    }
                }
            }
            if (fflag == 0)
            {
                cout << 0 << endl;
                break;
            }
            if (flag == 0)
            {
                cout << 1 << endl;
                break;
            }
        }
    }
    return 0;
}