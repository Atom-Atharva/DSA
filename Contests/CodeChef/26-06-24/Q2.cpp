#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<bool> values(n, 0);

        bool perms = true;
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;

            while (val <= n)
            {
                if (values[val - 1] == 0)
                {
                    values[val - 1] = 1;
                    break;
                }
                val++;
            }
            if (val > n)
            {
                perms = false;
            }
        }

        (perms) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}