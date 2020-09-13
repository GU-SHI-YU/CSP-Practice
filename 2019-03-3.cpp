#include <iostream>
#include <string.h>

using namespace std;

char temp[9], disk[1005][85000] = {""};

int main()
{
    ios::sync_with_stdio(false);
    int n, s, l, m, max;
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 0; i < l; i++)
    {
        int a;
        scanf("%d%*c", &a);
        fgets(disk[a], 85000, stdin);
        if (i == 0)
            max = strlen(disk[a]) / 8;
    }
    scanf("%d", &m);
    while (m--)
    {
        int b;
        scanf("%d", &b);
        int band = b / s;
        int diskNo = band % n;
        int block = b % s + band / (n - 1) * s;
        if (block >= max || disk[diskNo][0] == '\0' && n - 1 > l)
            puts("-");
        else if (disk[diskNo][0] != '\0')
        {
            for (int i = 0; i < 8; i++)
                putchar(disk[diskNo][block * 8 + i]);
            puts("");
        }
        else
        {
            int ans = 0, k;
            for (int i = 0; i < n; i++)
            {
                if (i != diskNo)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        temp[j] = disk[diskNo][block * 8 + j];
                    }
                    temp[8] = '\0';
                    sscanf(temp, "%x", &k);
                    ans ^= k;
                }
            }
            printf("%08X\n", ans);
        }
    }
    return 0;
}