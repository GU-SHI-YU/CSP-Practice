#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int r, g, y;
    cin >> r >> y >> g;
    int n;
    cin >> n;
    long long ans = 0;
    while (n--)
    {
        int k, t;
        cin >> k >> t;
        if (k == 2)
            ans += t + r;
        else if (k == 0 || k == 1)
            ans += t;
    }
    cout << ans << endl;
    return 0;
}