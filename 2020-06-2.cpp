#include <algorithm>
#include <cstdio>

using namespace std;

struct Node
{
    int index;
    int value;
};

bool cmp(Node a, Node b)
{
    return a.index < b.index;
}

int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    Node *u = new Node[a];
    Node *v = new Node[b];
    for (int i = 0; i < a; i++)
    {
        int index, value;
        scanf("%d%d", &index, &value);
        Node temp = {index, value};
        u[i] = temp;
    }
    for (int i = 0; i < b; i++)
    {
        int index, value;
        scanf("%d%d", &index, &value);
        Node temp = {index, value};
        v[i] = temp;
    };
    sort(u, u + a, cmp);
    sort(v, v + b, cmp);
    int i = 0, j = 0;
    long long result = 0;
    while (i < a && j < b)
    {
        if (u[i].index == v[j].index)
        {
            result += u[i].value * v[j].value;
            i++;
            j++;
        }
        else if (u[i].index < v[j].index)
            i++;
        else
            j++;
    }
    printf("%lld", result);
    return 0;
}