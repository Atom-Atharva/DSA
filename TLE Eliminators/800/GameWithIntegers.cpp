// https://codeforces.com/problemset/problem/1899/A

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

        if (n % 3 == 0)
        {
            cout << "Second\n";
        }
        else
        {
            cout << "First\n";
        }
    }
    return 0;
}