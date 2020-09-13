#include <cstdio>
#include <vector>

using namespace std;

struct Node
{
    int x;
    int y;
};

vector<Node> node[2];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char type;
        scanf("%d %d %c", &x, &y, &type);
        Node temp = {x, y};
        node[type - 'A'].push_back(temp);
    }
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        long long sign = a + b * node[0][0].x + c * node[0][0].y;
        bool flag = false;
        for (auto n : node[0])
        {
            long long signt = a + b * n.x + c * n.y;
            if (sign * signt < 0)
                flag = true;
        }
        if (flag)
        {
            printf("No\n");
            continue;
        }
        for (auto n : node[1])
        {
            long long signt = a + b * n.x + c * n.y;
            if (sign * signt > 0)
                flag = true;
        }
        if (flag)
        {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
    return 0;
}
