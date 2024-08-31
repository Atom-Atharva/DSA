// https://codeforces.com/problemset/problem/1878/C

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long n, k, x;
        cin >> n >> k >> x;

        // Find Range
        long long st = (k * (k + 1)) / 2;
        long long en = ((n * (n + 1)) / 2) - (((n - k) * (n - k + 1)) / 2);

        // Check Range
        (x >= st && x <= en) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}