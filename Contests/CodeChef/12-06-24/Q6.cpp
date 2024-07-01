#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long A;
        cin >> A;

        long long B = 2 * A;
        long long C = pow(A, A);

        for (long long i = B + 1; i < pow(A, A); i++)
        {
            long long power = pow(A, A);
            if (power % i == 0)
            {
                C = i;
                break;
            }
        }
        cout << B << " " << C << endl;
    }
    return 0;
}