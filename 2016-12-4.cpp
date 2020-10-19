#include <iostream>

using namespace std;

int dp[1005][1005];
int s[1005][1005];
int sum[1005];
int a[1005];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        s[i][i] = i;
    }
    for (int len = 1; len < n; len++)
    {
        for (int start = 1; start <= n - len; start++)
        {
            int mink;
            int temp = INT_MAX;
            int end = start + len;
            for (int k = s[start][end - 1]; k <= s[start + 1][end]; k++)
            {
                if (temp > (dp[start][k] + dp[k + 1][end] + sum[end] - sum[start - 1]))
                {
                    mink = k;
                    temp = dp[start][k] + dp[k + 1][end] + sum[end] - sum[start - 1];
                }
            }
            s[start][end] = mink;
            dp[start][end] = temp;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}