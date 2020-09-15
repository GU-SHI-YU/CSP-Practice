#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }
    int j = 1;
    while (q.size() != 1)
    {
        if (j % 10 == k || j % k == 0)
        {
            q.pop();
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        j++;
    }
    cout << q.front();
    return 0;
}