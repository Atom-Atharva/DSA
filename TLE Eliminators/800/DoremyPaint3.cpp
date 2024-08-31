// https://codeforces.com/problemset/problem/1890/A

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int a = -1;
        int freqA = 0;
        int b = -1;
        int freqB = 0;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int element;
            cin >> element;

            if (element == a)
            {
                freqA++;
                continue;
            }
            else if (element == b)
            {
                freqB++;
                continue;
            }
            else if (a != -1 && b != -1)
            {
                flag = false;
            }

            if (a == -1)
            {
                a = element;
                freqA++;
                continue;
            }
            if (b == -1)
            {
                b = element;
                freqB++;
                continue;
            }
        }

        if (!flag)
        {
            cout << "NO\n";
        }
        else
        {
            if (freqA == freqB || abs(freqA - freqB) == 1 || freqA == 0 || freqB == 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}