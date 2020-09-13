#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Element
{
    string type;
    int father;
    int line;
    int level;
    string id;

    Element(string _type, string _id, int _father, int _line, int _level)
    {
        type = _type;
        id = _id;
        father = _father;
        line = _line;
    }
};

vector<Element> elements;

int main()
{
    ios ::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        int level = temp.find('.');
        temp = temp.substr(level + 1);
        if (level > last)
        {
        }
    }
    return 0;
}