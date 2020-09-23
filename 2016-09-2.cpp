#include <iostream>

using namespace std;

bool tickect[20][5];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        bool over = false;
        cin >> num;
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                bool flag = true;
                for (int k = 0; k < num; k++)
                {
                    if (tickect[i][j + k] || j + k >= 5)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    for (int k = 0; k < num; k++)
                    {
                        cout << i * 5 + j + k + 1 << " ";
                        tickect[i][j + k] = true;
                    }
                    cout << endl;
                    over = true;
                }
                if (over)
                {
                    break;
                }
            }
            if (over)
            {
                break;
            }
        }
        if (!over)
        {
            for (int i = 0; i < 20; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (tickect[i][j] == false && num != 0)
                    {
                        tickect[i][j] = true;
                        cout << i * 5 + j + 1 << " ";
                        num--;
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}