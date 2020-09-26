#include <iostream>

using namespace std;

int table[19][11];
int block[5][5];

int main()
{
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 15; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cin >> table[i][j];
        }
    }
    for (int j = 1; j <= 10; j++)
    {
        table[16][j] = 1;
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> block[i][j];
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 4; j >= 1; j--)
        {
            for (int k = 0; k < 4; k++)
            {
                if (block[j][k + 1] == 1 && table[i - 4 + j][k + n] == 1)
                {
                    for (int ii = 1; ii <= 4; ii++)
                    {
                        for (int jj = 1; jj <= 4; jj++)
                        {
                            if (i - 5 + ii >= 1 && block[ii][jj] == 1)
                            {
                                table[i - 5 + ii][jj + n - 1] = block[ii][jj];
                            }
                        }
                    }
                    for (int ii = 1; ii <= 15; ii++)
                    {
                        for (int jj = 1; jj <= 10; jj++)
                        {
                            cout << table[ii][jj] << " ";
                        }
                        cout << endl;
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}