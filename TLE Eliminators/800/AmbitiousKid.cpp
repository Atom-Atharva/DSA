// https://codeforces.com/problemset/problem/1866/A

#include <iostream>
using namespace std;
#include <climits>

int main()
{
    int n;
    cin >> n;

    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        minimum = min(minimum, abs(num));
    }

    cout << minimum << endl;
    return 0;
}