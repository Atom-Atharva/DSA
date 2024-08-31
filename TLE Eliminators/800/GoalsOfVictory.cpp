// https://codeforces.com/problemset/problem/1877/A

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

        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int element;
            cin >> element;

            sum += element;
        }

        sum = 0 - sum;
        cout << sum << endl;
    }
    return 0;
}