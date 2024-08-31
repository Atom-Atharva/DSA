// https://codeforces.com/problemset/problem/1875/A

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int a, b, n;
        cin >> a >> b >> n;

        long long sum = b;
        for (int i = 0; i < n; i++)
        {
            int tool;
            cin >> tool;

            sum += (tool < a) ? tool : a - 1;
        }

        cout << sum << endl;
    }
    return 0;
}