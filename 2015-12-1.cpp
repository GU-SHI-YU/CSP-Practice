#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    int ans = 0;
    while (n > 0)
    {
        ans += n % 10;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}