#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Delete the leading and trailing spaces*/
string Delete_Space(string str)
{
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ') + 1);
    return str;
}

int main()
{
    ios::sync_with_stdio(false);
    int w, ans = 0;
    bool flag = false;
    string str = "";
    vector<pair<string, int>> vec; // 1新项目 ，2 子项目，3段落
    cin >> w;                      //终端宽度
    //检查最开始是否是空行
    while (getline(cin, str))
    {
        //检测是否为空行
        if (str.size() == count(str.begin(), str.end(), ' '))
            flag = true;
        //非空行时
        else
        {
            //上一行为空行时或者不存在上一行时
            if (flag || vec.empty())
            { //新项目
                if (str.size() >= 2 && str.substr(0, 2) == string("* "))
                {
                    vec.push_back(make_pair(Delete_Space(str.substr(2)), 1));
                }
                else
                { //为段落时
                    vec.push_back(make_pair(Delete_Space(str), 3));
                }
                flag = false;
            }
            //上一行非空行
            else
            { //查看上一行标志类型
                pair<string, int> &last = vec.back();
                //上一行为项目时
                if (last.second <= 2)
                {
                    //为项目的内容时，直接空格隔开，然后连接
                    if (str.size() >= 2 && str[0] == ' ' && str[1] == ' ')
                    {
                        last.first += " ";
                        last.first += Delete_Space(str.substr(2));
                    }
                    //与上一个是同一个项目列表
                    else if (str.size() >= 2 && str[0] == '*' && str[1] == ' ')
                        vec.push_back(make_pair(Delete_Space(str.substr(2)), 2));
                    else //为段落时
                        vec.push_back(make_pair(Delete_Space(str), 3));
                }
                else
                {                                                          //上一行为段落时
                    if (str.size() >= 2 && str[0] == '*' && str[1] == ' ') //新项目
                        vec.push_back(make_pair(Delete_Space(str.substr(2)), 1));
                    else
                    { //段落内容
                        last.first += " ";
                        last.first += Delete_Space(str);
                    }
                }
            }
        }
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        string str = vec[i].first;
        //输出中间空行
        if (vec[i].second != 2 && i > 0)
            ans++;
        //为项目时
        if (vec[i].second <= 2)
        {
            if (str.size() == 0) //是空行
                ans++;
            else
            { //非空行
                for (int i = 0; i < str.size(); i += (w - 3))
                {
                    //删去每行开始可能的空格
                    while (i < str.size() && str[i] == ' ')
                        i++;
                    ans++;
                }
            }
        }
        else
        { //为段落时
            for (int i = 0; i < str.size(); i += w)
            {
                //删去每行开始可能的空格
                while (i < str.size() && str[i] == ' ')
                    i++;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}