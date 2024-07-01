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

        int x, y;
        cin >> x >> y;

        // PER HOUR MONEY
        float yph = (float)y / 2;

        int cost = 0;
        if (yph > x)
        {
            if (n % 2 == 0)
            {
                cost = (n / 2) * y;
            }
            else
            {
                cost = ((n - 1) / 2 * y) + x;
            }
        }
        else
        {
            cost = n * x;
        }

        cout << cost << endl;
    }
    return 0;
}