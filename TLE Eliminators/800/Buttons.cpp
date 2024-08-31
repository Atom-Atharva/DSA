// https://codeforces.com/problemset/problem/1858/A

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        long long anna = 0, katie = 0;
        anna += (c + 1) / 2;
        katie += c / 2;

        anna += a;
        katie += b;

        if (anna > katie)
        {
            cout << "First\n";
        }
        else
        {
            cout << "Second\n";
        }
    }
    return 0;
}