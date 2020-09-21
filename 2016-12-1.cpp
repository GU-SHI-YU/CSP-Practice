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
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        int bigger = 0;
        int smaller = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == num)
                break;
            smaller++;
        }
        for (int j = n - 1; j >= 0; j--)
        {
            if (a[j] == num)
                break;
            bigger++;
        }
        if (bigger == smaller)
        {
            cout << num << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}