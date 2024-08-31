// https://codeforces.com/problemset/problem/1896/A

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

        bool sortable = false;
        for (int i = 0; i < n; i++)
        {
            int element;
            cin >> element;

            if (i == 0 && element == 1)
            {
                sortable = true;
            }
        }

        (sortable) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}