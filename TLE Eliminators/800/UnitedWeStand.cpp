// https://codeforces.com/problemset/problem/1859/A

#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int arr[n];
        int maximum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maximum = max(maximum, arr[i]);
        }

        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == maximum)
            {
                b.push_back(arr[i]);
            }
            else
            {
                a.push_back(arr[i]);
            }
        }
        if (a.size() == 0)
        {
            cout << -1 << endl;
            continue;
        }

        cout << a.size() << " " << b.size() << endl;
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}