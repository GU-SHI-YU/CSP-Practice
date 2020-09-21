#include <iostream>

using namespace std;

int a[1005];

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (m--)
    {
        int num, step;
        cin >> num >> step;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == num)
            {
                if (step > 0)
                {
                    int temp = a[i];
                    for (int j = i; j < i + step; j++)
                    {
                        a[j] = a[j + 1];
                    }
                    a[i + step] = temp;
                }
                else
                {
                    int temp = a[i];
                    for (int j = i; j > i + step; j--)
                    {
                        a[j] = a[j - 1];
                    }
                    a[i + step] = temp;
                }
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}