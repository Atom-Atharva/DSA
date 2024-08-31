// https://codeforces.com/problemset/problem/1881/A

#include <iostream>
using namespace std;

bool isSubstring(string x, string s)
{
    if (x.length() < s.length())
    {
        return false;
    }

    for (int i = 0; i <= x.length() - s.length(); i++)
    {
        string sub = x.substr(i, s.length());
        if (sub == s)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s;

        int count = 0;
        bool found = false;
        while (x.length() < 1000)
        {
            bool check = isSubstring(x, s);
            if (check)
            {
                found = true;
                break;
            }

            x += x;
            count++;
        }

        found ? cout << count << endl : cout << -1 << endl;
    }

    return 0;
}