#include <iostream>
using namespace std;
#include <unordered_map>

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int maxContinuous = 1;
    int continuous = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            continuous++;
        }
        else
        {
            maxContinuous = max(maxContinuous, continuous);
            continuous = 1;
        }
    }
    maxContinuous = max(maxContinuous, continuous);

    cout << maxContinuous + 1    << endl;

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