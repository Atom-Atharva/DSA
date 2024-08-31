// https://www.naukri.com/code360/problems/count-derangements_873861

#include <iostream>
using namespace std;
#include <vector>

// Space Optimization
class SolutionTAB
{
    int MOD = 1e9 + 7;

public:
    long long int countDerangements(int n)
    {
        // FOR n == 1;
        long long int first = 0;
        // FOR n == 2;
        long long int second = 1;

        for (int i = 2; i < n; i++)
        {
            long long int ans = (i * (second + first) % MOD) % MOD;
            first = second;
            second = ans;
        }

        return second;
    }
};

// Tabulation Method
class SolutionTAB
{
    int MOD = 1e9 + 7;

public:
    long long int countDerangements(int n)
    {
        vector<long long int> dp(n, -1);
        // FOR n == 1;
        dp[0] = 0;
        // FOR n == 2;
        dp[1] = 1;

        for (int i = 2; i < n; i++)
        {
            dp[i] = (i * (dp[i - 2] + dp[i - 1]) % MOD) % MOD;
        }

        return dp[n - 1];
    }
};

// Memomization
class SolutionMEM
{
    int MOD = 1e9 + 7;

    long long int countDerangements(int n, vector<long long> &dp)
    {
        // Base Case
        if (n <= 2)
        {
            return n - 1;
        }
        if (dp[n - 1] != -1)
        {
            return dp[n - 1];
        }

        // Recursive Calls
        return dp[n - 1] = ((n - 1) * (countDerangements(n - 2, dp) + countDerangements(n - 1, dp)) % MOD) % MOD;
    }

public:
    long long int countDerangements(int n)
    {
        vector<long long> dp(n, -1);
        return countDerangements(n, dp);
    }
};

// Recursion
class SolutionREC
{
public:
    long long int countDerangements(int n)
    {
        // Base Case
        if (n <= 2)
        {
            return n - 1;
        }

        // Recursive Calls
        return (n - 1) * (countDerangements(n - 2) + countDerangements(n - 1));
    }
};