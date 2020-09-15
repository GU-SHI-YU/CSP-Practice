#include <algorithm>
#include <iostream>

using namespace std;

int a[1005];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int res = 10001;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = a[i + 1] - a[i];
        if (res > temp)
            res = temp;
    }
    cout << res;
    return 0;
}