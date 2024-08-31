#include <iostream>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;

    int arr[n + 1];
    arr[0] = 0;
    int odds = 0;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (num % 2 != 0)
        {
            odds++;
        }
        arr[i] = odds;
    }

    for (int i = 0; i < q; i++)
    {
        int l, r, num;
        cin >> l >> r >> num;

        int oddsInRange = arr[r] - arr[l - 1];
        int newOdds = (num % 2 == 1) ? r - l + 1 - oddsInRange : -1 * oddsInRange;

        ((odds + newOdds) % 2 == 1) ? cout << "Yes\n" : cout << "No\n";
    }

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