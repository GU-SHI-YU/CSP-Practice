#include <iostream>

using namespace std;

int a[1005];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        int temp;
        cin >> temp;
        a[temp]++;
        cout << a[temp] << " ";
    }
    return 0;
}