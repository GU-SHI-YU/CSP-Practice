#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    int ans = 0;
    cin >> n;
    n = n / 10;
    ans += n / 5 * 7;
    n = n % 5;
    ans += n / 3 * 4;
    n = n % 3;
    ans += n;
    cout << ans << endl;
    return 0;
}