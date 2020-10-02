#include <iostream>

using namespace std;

int a[10005];

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
    }
    int max = -1;
    int k = -1;
    for (int i = 0; i < 10005; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            k = i;
        }
    }
    cout << k;
    return 0;
}