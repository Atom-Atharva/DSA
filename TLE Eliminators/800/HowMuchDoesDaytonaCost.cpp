// https://codeforces.com/problemset/problem/1878/A

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        cin >> n >> k;

        bool found = false;
        for (int i = 0; i < n; i++)
        {
            int element;
            cin >> element;

            if (element == k)
            {
                found = true;
            }
        }

        if (found)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}