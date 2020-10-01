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
        int temp;
        cin >> temp;
        a[temp]++;
    };
    while (true)
    {
        int k = -1;
        int max = 0;
        for (int i = 0; i <= 1000; i++)
        {
            if (a[i] > max)
            {
                k = i;
                max = a[i];
            }
        }
        if (max == 0)
            break;
        cout << k << " " << max << endl;
        a[k] = 0;
    };
    return 0;
}