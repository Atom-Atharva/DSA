// https://codeforces.com/problemset/problem/1855/B

#include <iostream>
using namespace std;
#include <vector>

void solve()
{
    long long int n;
    cin >> n;

    long long count = 1;
    while (n % count == 0)
    {
        count++;
    }

    cout << count - 1 << endl;
    return;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
    return 0;
}