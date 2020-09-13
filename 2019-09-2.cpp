#include <iostream>

using namespace std;

int tree[1005] = {0};
int apple[1005] = {0};
bool drop[1005] = {false};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int temp = 0;
            cin >> temp;
            if (temp > 0)
            {
                if (temp < tree[i] + apple[i])
                    drop[i] = true;
                tree[i] = temp;
                apple[i] = 0;
            }
            else
            {
                apple[i] += temp;
            }
        }
    }
    int T = 0;
    int D = 0;
    int E = 0;
    for (int i = 0; i < n; i++)
    {
        T += tree[i] + apple[i];
        if (drop[i])
            D++;
        if (i == 0)
        {
            if (drop[0] && drop[n - 1] && drop[1])
                E++;
        }
        else if (i == n - 1)
        {
            if (drop[n - 1] && drop[n - 2] && drop[0])
                E++;
        }
        else
        {
            if (drop[i] && drop[i - 1] && drop[i + 1])
                E++;
        }
    }
    cout << T << " " << D << " " << E << endl;
    return 0;
}