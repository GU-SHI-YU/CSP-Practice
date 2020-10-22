#include <iostream>
#include <queue>

using namespace std;

struct Direct
{
    int col;
    int row;
};

Direct directs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Node
{
    int row;
    int col;
    int step;

    Node(int _row, int _col, int _step) : row(_row), col(_col), step(_step){};

    bool operator==(const Node &a) const
    {
        return col == a.col && row == a.row;
    }
};

queue<Node> q;
bool visited[105][105][305];
int n, m, t;

int BFS(Node dest)
{
    Node a(1, 1, 0);
    visited[a.row][a.col][a.step] = true;
    q.push(a);
    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if (temp == dest)
            return temp.step;
        for (int i = 0; i < 4; i++)
        {
            Node b(temp.row + directs[i].row, temp.col + directs[i].col, temp.step + 1);
            if (b.col < 1 || b.col > m || b.row < 1 || b.row > n)
                continue;
            if (visited[b.row][b.col][b.step])
                continue;
            visited[b.row][b.col][b.step] = true;
            q.push(b);
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> t;
    while (t--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        for (int i = a; i <= b; i++)
        {
            visited[x][y][i] = true;
        }
    }
    int ans = BFS(Node(n, m, INT_MAX));
    cout << ans << endl;
    return 0;
}