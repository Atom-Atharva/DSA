// https://codeforces.com/problemset/problem/1901/A

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, x;
        cin >> n >> x;

        int maxDistance = 0;
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            int dist = a - prev;
            maxDistance = max(dist, maxDistance);
            prev = a;
        }
        maxDistance = max(maxDistance, 2 * (x - prev));

        cout << maxDistance << endl;
    }
    return 0;
}