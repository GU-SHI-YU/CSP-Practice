#include <cmath>
#include <iostream>

using namespace std;

int grid[19][10];
int pattern[4][4];

int main()
{
    ios::sync_with_stdio(false);
    int pos(0);
    for (int i = 0; i < 150; i++)
        cin >> grid[i / 10][i % 10];
    for (int i = 0; i < 16; i++)
        cin >> pattern[i / 4][i % 4];
    cin >> pos;
    pos -= 1;
    int notNull;
    for (int i = 3; i >= 0; i--)
    {
        if (pattern[i][0] | pattern[i][1] | pattern[i][2] | pattern[i][3])
        {
            notNull = i;
            break;
        }
    }
    int row = 0;
    while (1)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if ((row + notNull == 15) || (grid[row + i][pos + j] & pattern[i][j]))
                    goto out;
        ++row;
    }
out:
    row -= 1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            grid[row + i][pos + j] |= pattern[i][j];

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    return 0;
}