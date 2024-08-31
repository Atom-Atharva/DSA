// https://codeforces.com/problemset/problem/1857/A

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

        int odd = 0;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;

            if (num % 2 != 0)
                odd++;
        }

        (odd % 2 == 0) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}