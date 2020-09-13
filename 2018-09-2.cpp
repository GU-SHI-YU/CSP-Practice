#include <iostream>

using namespace std;

bool time[1000005] ={ false };

int main()
{
    ios::sync_with_stdio(false);
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a;j < b;j++)
        {
            time[j] = true;
        }
    }
    for (int i = 0;i < n;i++)
    {
        int c, d;
        cin >> c >> d;
        for (int j = c; j < d;j++)
        {
            if (time[j])
                ans++;
        }
    }
    cout << ans;
    return 0;
}