// https://codeforces.com/problemset/problem/1900/A

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool infinite = false;
        int water = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {
                count++;
            }
            else
            {
                water += count;
                count = 0;
            }
            if (count >= 3)
            {
                infinite = true;
            }
        }
        water += count;

        if (infinite)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << water << endl;
        }
    }
    return 0;
}