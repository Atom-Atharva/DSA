// https://codeforces.com/problemset/problem/1903/A

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

        bool sorted = true;
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;

            if (ele < prev)
            {
                sorted = false;
            }
            prev = ele;
        }

        if (k >= 2)
        {
            cout << "YES\n";
        }
        else
        {
            if (sorted)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}