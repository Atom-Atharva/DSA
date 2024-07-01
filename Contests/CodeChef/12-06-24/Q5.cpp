#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

vector<int> findPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> prime;
    for (int i = 0; i < n + 1; i++)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
        }
    }
    return prime;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        int close = sqrt(n);

        vector<int> primes = findPrimes(n);

        bool found = false;
        for (int i = 0; i < primes.size() - 2; i++)
        {
            int l = i + 1;
            int r = primes.size() - 1;
            while (l < r)
            {
                int operation = (primes[l] * primes[l]) + (primes[r] * primes[r]) + (primes[i] * primes[i]);
                if (operation == n)
                {
                    found = true;
                    break;
                }
                else if (operation < n)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            if (found)
            {
                break;
            }
        }

        if (found)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}