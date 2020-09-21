#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    if (T <= 3500)
    {
        cout << T << endl;
        return 0;
    }
    for (int i = 1; i <= 1500; i++)
        if (int(i * 0.97) + 3500 == T)
        {
            cout << i + 3500 << endl;
            return 0;
        }
    for (int i = 1501; i <= 4500; i++)
        if (int(i - 1500 * 0.03 - (i - 1500) * 0.1) + 3500 == T)
        {
            cout << i + 3500 << endl;
            return 0;
        }
    for (int i = 4501; i <= 9000; i++)
        if (int(i - 1500 * 0.03 - 3000 * 0.1 - (i - 4500) * 0.2) + 3500 == T)
        {
            cout << i + 3500 << endl;
            return 0;
        }
    for (int i = 9001; i <= 35000; i++)
        if (int(i - 1500 * 0.03 - 3000 * 0.1 - 4500 * 0.2 - (i - 9000) * 0.25) + 3500 == T)
        {
            cout << i + 3500 << endl;
            return 0;
        }
    for (int i = 35001; i <= 55000; i++)
        if (int(i - 1500 * 0.03 - 3000 * 0.1 - 4500 * 0.2 - 26000 * 0.25 - (i - 35000) * 0.3) + 3500 == T)
        {
            cout << i + 3500 << endl;
            return 0;
        };
    for (int i = 55001; i <= 80000; i++)
        if (int(i - 1500 * 0.03 - 3000 * 0.1 - 4500 * 0.2 - 26000 * 0.25 - 20000 * 0.3 - (i - 55000) * 0.35) + 3500 == T)
        {
            cout << i + 3500 << endl;
            return 0;
        }
    for (int i = 80001; i <= 100000; i++)
        if (int(i - 1500 * 0.03 - 3000 * 0.1 - 4500 * 0.2 - 26000 * 0.25 - 20000 * 0.3 - 25000 * 0.35 - (i - 80000) * 0.45) + 3500 == T)
        {
            cout << i + 3500 << endl;
            return 0;
        }
    return 0;
}