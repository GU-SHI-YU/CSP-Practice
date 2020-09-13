#include <iostream>

using namespace std;

int ball[105];

int main()
{
    ios::sync_with_stdio(false);
    int n, l, t;
    cin >> n >> l >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> ball[i];
    }
    while (t--)
    {
        for (int i = 0; i < n; i++)
        {
            ball[i]++;
            if (ball[i] == l)
                ball[i] *= -1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i != j && (ball[i] == ball[j] || ball[i] + ball[j] == 0))
                {
                    ball[i] *= -1;
                    ball[j] *= -1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << (ball[i] > 0 ? ball[i] : -ball[i]) << " ";
    }
    return 0;
}