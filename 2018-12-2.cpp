#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int r, y, g;
    cin >> r >> y >> g;
    int cycle = r + y + g;
    int n;
    cin >> n;
    long long ans = 0;
    while (n--)
    {
        int k, t;
        cin >> k >> t;
        int a = ans % cycle;
        switch (k)
        {
        case 0:
            ans += t;
            break;
        case 1:
            if (t > a)
                ans += t - a;
            else if (t + g > a)
                break;
            else if (t + g + y > a)
                ans += t + g + y - a + r;
            else if (t + g + y + r > a)
                ans += t + g + y + r - a;
            break;
        case 2:
            if (t > a)
                ans += t - a + r;
            else if (t + r > a)
                ans += t + r - a;
            else if (t + r + g > a)
                break;
            else if (t + r + g + y > a)
                ans += t + r + g + y - a + r;
            break;
        case 3:
            if (t > a)
                break;
            else if (t + y > a)
                ans += t + y - a + r;
            else if (t + y + r > a)
                ans += t + y + r - a;
            else if (t + y + r + g > a)
                break;
            break;
        default:
            break;
        }
    }
    cout << ans << endl;
    return 0;
}