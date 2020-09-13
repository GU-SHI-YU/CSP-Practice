#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (i == 0)
            a.push_back(temp);
        if (i == n - 1)
            a.push_back(temp);
        if (i == n / 2)
            a.push_back(temp);
        if (n % 2 == 0 && i == n / 2 - 1)
            a.push_back(temp);
    }
    sort(a.begin(), a.end());
    printf("%d ", a.back());
    if (a.size() == 3)
        printf("%d ", a[1]);
    else
    {
        if ((a[1] + a[2]) % 2)
            printf(".1f ", (a[1] * 1.0 + a[2]) / 2);
        else
            printf("%d ", (a[1] + a[2]) / 2);
    }
    printf("%d", a.front());
    return 0;
}