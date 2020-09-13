#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct IP
{
    unsigned int r;
    unsigned int l;
    unsigned int addr;
    unsigned int len;
    unsigned int a[4];

    bool operator<(const IP& a) const
    {
        if (addr != a.addr)
            return addr < a.addr;
        return len < a.len;
    }

    IP(string& s)
    {
        addr = 0;
        a[0] = a[1] = a[2] = a[3] = 0;
        int i = 0;
        int split = s.find('/');
        if (split == string::npos)
        {
            int lastP = 0;
            int position = 0;
            while ((position = s.find('.', lastP)) != string::npos)
            {
                a[i++] = atoi(s.substr(lastP, position - lastP).c_str());
                lastP = position + 1;
            }
            a[i++] = atoi(s.substr(lastP).c_str());
            len = i * 8;
            for (int j = 0;j < 4;j++)
            {
                addr += a[j] * pow(256, 3 - j);
            }
        }
        else
        {
            len = atoi(s.substr(split + 1).c_str());
            s = s.substr(0, split);
            int lastP = 0;
            int position = 0;
            while ((position = s.find('.', lastP)) != string::npos)
            {
                a[i++] = atoi(s.substr(lastP, position - lastP).c_str());
                lastP = position + 1;
            }
            a[i++] = atoi(s.substr(lastP).c_str());
            for (int j = 0;j < 4;j++)
            {
                addr += a[j] * pow(256, 3 - j);
            }
        }
        l = addr >> (32 - len) << (32 - len);
        r = addr | ((1ull << (32 - len)) - 1);
    }

    IP(unsigned int _addr, unsigned int* _a, unsigned int _len)
    {
        addr = _addr;
        for (int i = 0;i < 4;i++)
        {
            a[i] = _a[i];
        }
        len = _len;
        l = addr >> (32 - len) << (32 - len);
        r = addr | ((1ull << (32 - len)) - 1);
    }
};

vector<IP> v;

void union1()
{
    int i = 0;
    while (i < v.size() - 1)
    {
        while (v[i].l <= v[i + 1].l && v[i].r >= v[i + 1].r)
        {
            v.erase(v.begin() + i + 1, v.begin() + i + 2);
        }
        i++;
    }
}

void union2()
{
    int i = 0;
    while (i < v.size() - 1)
    {
        if (v[i].len == v[i + 1].len && v[i].len > 0)
        {
            IP temp = IP(v[i].addr, v[i].a, v[i].len - 1);
            unsigned int ll = v[i].l < v[i+1].l ? v[i].l : v[i+1].l;
            unsigned int rr = v[i].r > v[i+1].r ? v[i].r : v[i+1].r;
            if (ll == temp.l && rr == temp.r)
            {
                v[i] = temp;
                v.erase(v.begin() + i + 1, v.begin() + i + 2);
                if (i != 0)
                {
                    i--;
                    continue;
                }
            }
        }
        i++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        v.push_back(IP(s));
    }
    sort(v.begin(), v.end());
    union1();
    union2();
    for (int i = 0;i < v.size();i++)
    {
        cout << v[i].a[0];
        for (int j = 0;j < 3;j++)
        {
            cout <<"."<< v[i].a[j + 1];
        }
        cout << "/" << v[i].len << endl;
    }
    return 0;
}