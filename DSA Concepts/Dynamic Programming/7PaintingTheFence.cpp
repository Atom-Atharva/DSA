// https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

#include <iostream>
using namespace std;
#include <vector>

// Space Optimization
class Solution
{
    int MOD = 1e9 + 7;

public:
    long long countWays(int n, int k)
    {
        if (n == 1)
        {
            return k;
        }

        long long int first = k;
        long long int second = ((long long)k + ((long long)k * ((long long)k - 1)) % MOD) % MOD;

        for (int i = 2; i < n; i++)
        {
            long long int same = (first % MOD * (k - 1)) % MOD;
            long long int diff = (second % MOD * (k - 1)) % MOD;

            long long int curr = (same + diff) % MOD;

            first = second;
            second = curr;
        }

        return second;
    }
};

// Tabulation
class SolutionTAB
{
    int MOD = 1e9 + 7;

public:
    long long countWays(int n, int k)
    {
        vector<long long int> dp(n);
        dp[0] = k;
        dp[1] = ((long long)k + ((long long)k * ((long long)k - 1)) % MOD) % MOD;

        for (int i = 2; i < n; i++)
        {
            long long int same = (dp[i - 2] % MOD * (k - 1)) % MOD;
            long long int diff = (dp[i - 1] % MOD * (k - 1)) % MOD;

            dp[i] = (same + diff) % MOD;
        }

        return dp[n - 1];
    }
};

// Memomization
class SolutionMEM
{
    int MOD = 1e9 + 7;

    long long countWaysHelper(int n, int k, vector<long long int> &dp)
    {
        // Base Case
        if (n == 1)
        {
            return k;
        }
        if (n == 2)
        {
            return ((long long)k + ((long long)k * ((long long)k - 1)) % MOD) % MOD;
        }
        if (dp[n - 1] != -1)
        {
            return dp[n - 1];
        }

        long long int same = (countWaysHelper(n - 2, k, dp) % MOD * (k - 1)) % MOD;
        long long int diff = (countWaysHelper(n - 1, k, dp) % MOD * (k - 1)) % MOD;

        return dp[n - 1] = (same + diff) % MOD;
    }

public:
    long long countWays(int n, int k)
    {
        vector<long long int> dp(n, -1);
        return countWaysHelper(n, k, dp);
    }
};

class SolutionREC
{
    int MOD = 1e9 + 7;

    long long countWaysHelper(int n, int k)
    {
        // Base Case
        if (n == 1)
        {
            return k;
        }
        if (n == 2)
        {
            return (k + (k * (k - 1)) % MOD) % MOD;
        }

        long long int same = (countWaysHelper(n - 2, k) * (k - 1)) % MOD;
        long long int diff = (countWaysHelper(n - 1, k) * (k - 1)) % MOD;

        return (same + diff) % MOD;
    }

public:
    long long countWays(int n, int k)
    {
        return countWaysHelper(n, k);
    }
};