#include <iostream>

using namespace std;

int tree[1005] = {0};
int apple[1005] = {0};

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
        int temp = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            apple[i] += temp;
        }
    }
    int T = 0;
    int k = -1;
    int P = 1;
    for (int i = 0; i < n; i++)
    {
        T += tree[i] + apple[i];
        if (apple[i] < P)
        {
            k = i;
            P = apple[i];
        }
    }
    cout << T << " " << k + 1 << " " << -P << endl;
}