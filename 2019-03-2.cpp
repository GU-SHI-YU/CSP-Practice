#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    stack<char> op;
    stack<int> num;
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < 7; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num.push(s[i] - '0');
            else
            {
                if (s[i] == 'x')
                {
                    int a = num.top();
                    num.pop();
                    int b = s[++i] - '0';
                    num.push(a * b);
                }
                else if (s[i] == '/')
                {
                    int a = num.top();
                    num.pop();
                    int b = s[++i] - '0';
                    num.push(a / b);
                }
                else
                    op.push(s[i]);
            }
        }
        int ans = 0;
        while (op.size() != 0)
        {
            char c = op.top();
            op.pop();
            if (c == '+')
            {
                int a = num.top();
                num.pop();
                ans += a;
            }
            if (c == '-')
            {
                int a = num.top();
                num.pop();
                ans -= a;
            }
        }
        ans += num.top();
        num.pop();
        if (ans != 24)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}