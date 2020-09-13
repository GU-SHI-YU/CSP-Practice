#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct Pixel
{
    int r;
    int g;
    int b;
};

Pixel graph[1925][1085] = {0, 0, 0};
Pixel zip[1925][1085] = {0, 0, 0};

int toInt(string str)
{
    int num = 0;
    if (str[0] >= 'a')
        num += str[0] - 'a' + 10;
    else
        num += str[0] - '0';
    if (str[1] >= 'a')
        num = num * 16 + str[1] - 'a' + 10;
    else
        num = num * 16 + str[1] - '0';
    return num;
}

void out(char c)
{
    unsigned int a = (unsigned int)c;
    cout << "\\x" << setfill('0') << setw(2) << setiosflags(ios::uppercase) << hex << a;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    int p, q;
    cin >> m >> n;
    cin >> p >> q;
    int col = m / p;
    int row = n / q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string str;
            cin >> str;
            if (str.size() == 2)
            {
                string temp = "";
                temp.push_back(str[1]);
                temp.push_back(str[1]);
                graph[i][j].r = graph[i][j].g = graph[i][j].b = toInt(temp);
            }
            if (str.size() == 4)
            {
                string r = "";
                string b = "";
                string g = "";
                r.push_back(str[1]);
                b.push_back(str[3]);
                g.push_back(str[2]);
                r.push_back(str[1]);
                b.push_back(str[3]);
                g.push_back(str[2]);
                graph[i][j].r = toInt(r);
                graph[i][j].g = toInt(g);
                graph[i][j].b = toInt(b);
            }
            if (str.size() == 7)
            {
                string r = "";
                string b = "";
                string g = "";
                r.push_back(str[1]);
                b.push_back(str[5]);
                g.push_back(str[3]);
                r.push_back(str[2]);
                b.push_back(str[6]);
                g.push_back(str[4]);
                graph[i][j].r = toInt(r);
                graph[i][j].g = toInt(g);
                graph[i][j].b = toInt(b);
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int r = 0;
            int g = 0;
            int b = 0;
            for (int ii = i * q; ii < (i + 1) * q; ii++)
            {
                for (int jj = j * p; jj < (j + 1) * p; jj++)
                {
                    r += graph[ii][jj].r;
                    b += graph[ii][jj].b;
                    g += graph[ii][jj].g;
                }
            }
            r /= p * q;
            b /= p * q;
            g /= p * q;
            zip[i][j] = {r, g, b};
        }
    }
    string temp = "";
    Pixel last = {0, 0, 0};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (zip[i][j].r != last.r || zip[i][j].g != last.g || zip[i][j].b != last.b)
            {
                if (zip[i][j].r != 0 || zip[i][j].g != 0 || zip[i][j].b != 0)
                {
                    out(0x1B);
                    out(0x5B);
                    out(0x34);
                    out(0x38);
                    out(0x3B);
                    out(0x32);
                    out(0x3B);
                    temp = to_string(zip[i][j].r);
                    for (char c : temp)
                        out(c);
                    out(0x3B);
                    temp = to_string(zip[i][j].g);
                    for (char c : temp)
                        out(c);
                    out(0x3B);
                    temp = to_string(zip[i][j].b);
                    for (char c : temp)
                        out(c);
                    out(0x6D);
                }
                else
                {
                    out(0x1B);
                    out(0x5B);
                    out(0x30);
                    out(0x6D);
                }
            }
            out(0x20);
            last = zip[i][j];
        }
        if (last.r != 0 || last.g != 0 || last.b != 0)
        {
            out(0x1B);
            out(0x5B);
            out(0x30);
            out(0x6D);
        }
        out('\n');
        last = {0, 0, 0};
    }
    return 0;
}