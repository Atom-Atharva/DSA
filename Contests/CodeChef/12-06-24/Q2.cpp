#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int x, y;
        cin >> x >> y;

        int hrs = ((10 * (y - x)) / (100 - y));
        if (((10 * (y - x)) % (100 - y)) != 0)
        {
            hrs++;
        }

        cout << hrs << endl;
    }
    return 0;
}