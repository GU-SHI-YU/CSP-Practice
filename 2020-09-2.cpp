#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, k, t, xl, yd, xr, yu;
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    int pass = 0;
    int stay = 0;
    while (n--)
    {
        int count = 0;
        int flag = 0;
        for (int i = 0; i < t; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x >= xl && x <= xr && y >= yd && y <= yu)
            {
                if (flag == 0)
                    flag = 1;
                count++;
                if (count >= k)
                    flag = 2;
            }
            else
            {
                count = 0;
            }
        }
        if (flag == 1)
            pass++;
        if (flag == 2)
            stay++;
    }
    cout << pass + stay << endl;
    cout << stay << endl;
    return 0;
}