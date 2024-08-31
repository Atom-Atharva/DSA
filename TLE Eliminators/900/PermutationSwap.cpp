#include <iostream>
using namespace std;
#include <algorithm>

void solve()
{
    int n;
    cin >> n;

    int commonDivisor = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        int diff = abs(num - (i + 1));
        if (diff != 0)
        {
            commonDivisor = __gcd(commonDivisor, diff);
        }
    }
    cout << commonDivisor << endl;

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