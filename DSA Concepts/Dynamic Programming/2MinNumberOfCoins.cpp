// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <climits>

// GETTING RID OF TLE
class Solution
{
    int coins[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

public:
    vector<int> minPartition(int N)
    {
        vector<int> list;
        while (N > 0)
        {
            for (int i = 9; i >= 0; i--)
            {
                if (N - coins[i] >= 0)
                {
                    list.push_back(coins[i]);
                    N = N - coins[i];
                    break;
                }
            }
        }

        return list;
    }
};

// Dynamic Programming
class SolutionTAB
{
    int coins[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

public:
    vector<int> minPartition(int N)
    {
        vector<vector<int>> dp(N + 1);
        dp[0] = {};

        for (int i = 1; i <= N; i++)
        {
            vector<int> ans;
            int minSize = INT_MAX;
            for (int j = 0; j < 10; j++)
            {
                if (i - coins[j] >= 0)
                {
                    vector<int> curr = dp[i - coins[j]];
                    curr.push_back(coins[j]);

                    if (curr.size() < minSize)
                    {
                        ans = curr;
                        minSize = curr.size();
                    }
                }
            }

            sort(ans.begin(), ans.end(), greater<int>());
            dp[i] = ans;
        }

        return dp[N];
    }
};

// Memomization
class SolutionMEM
{
    int coins[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    vector<int> minNumberOfCoins(int N, vector<vector<int>> &dp)
    {
        // Base Case
        if (N == 0)
        {
            return {};
        }
        if (dp[N].size() != 0)
        {
            return dp[N];
        }

        vector<int> ans;
        int minSize = INT_MAX;
        for (int i = 0; i < 10; i++)
        {
            if (N - coins[i] >= 0)
            {
                vector<int> curr = minNumberOfCoins(N - coins[i], dp);
                curr.push_back(coins[i]);

                if (curr.size() < minSize)
                {
                    ans = curr;
                    minSize = curr.size();
                }
            }
        }

        return dp[N] = ans;
    }

public:
    vector<int> minPartition(int N)
    {
        vector<vector<int>> dp(N + 1);
        vector<int> ans = minNumberOfCoins(N, dp);
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};

// Recursion
class SolutionREC
{
    int coins[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

    vector<int> minNumberOfCoins(int N)
    {
        // Base Case
        if (N == 0)
        {
            return {};
        }

        vector<int> ans;
        int minSize = INT_MAX;
        for (int i = 0; i < 10; i++)
        {
            if (N - coins[i] >= 0)
            {
                vector<int> curr = minNumberOfCoins(N - coins[i]);
                curr.push_back(coins[i]);

                if (curr.size() < minSize)
                {
                    ans = curr;
                    minSize = curr.size();
                }
            }
        }

        return ans;
    }

public:
    vector<int> minPartition(int N)
    {
        vector<int> ans = minNumberOfCoins(N);
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};