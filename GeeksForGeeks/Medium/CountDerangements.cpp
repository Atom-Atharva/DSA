// https://www.codingninjas.com/studio/problems/count-derangements_873861

#include <iostream>
using namespace std;
#include <vector>

int M = 1e9 + 7;

// Space Optimization--
long long int countDerangements(int n)
{
    long long prev1 = 0;
    long long prev2 = 1;

    for (int i = 3; i <= n; i++)
    {
        long long curr = ((i - 1) * (prev2 + prev1) % M) % M;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

// Dynamic Approach--
long long int countDerangements(int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2]) % M) % M;
    }

    return dp[n];
}

// Memomization--
/*
long long int countDerangements(int n, vector<long long int> &dp)
{
    // Base Case--
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n - 1] != -1)
    {
        return dp[n - 1];
    }

    long long int ans = ((n - 1) * (countDerangements(n - 1, dp) + countDerangements(n - 2, dp)) % M) % M;

    return dp[n - 1] = ans;
}
long long int countDerangements(int n)
{
    vector<long long int> dp(n, -1);
    return countDerangements(n, dp);
}
*/