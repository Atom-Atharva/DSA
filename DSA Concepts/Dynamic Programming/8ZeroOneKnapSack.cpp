// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <iostream>
using namespace std;
#include <vector>

// Space Optimization
class Solution
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        // DP and Initialization
        vector<int> next(W + 1, 0);

        for (int pos = n - 1; pos >= 0; pos--)
        {
            vector<int> curr(W + 1, 0);
            for (int w = 1; w <= W; w++)
            {
                // Leave
                int value = next[w];

                // Take
                if (w - wt[pos] >= 0)
                {
                    value = max(value, next[w - wt[pos]] + val[pos]);
                }

                curr[w] = value;
            }

            next = curr;
        }

        return next[W];
    }
};

// Tabulation
class SolutionTAB
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        // DP and Initialization
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, 0));

        for (int w = 1; w <= W; w++)
        {
            for (int pos = n - 1; pos >= 0; pos--)
            {
                // Leave
                int value = dp[w][pos + 1];

                // Take
                if (w - wt[pos] >= 0)
                {
                    value = max(value, dp[w - wt[pos]][pos + 1] + val[pos]);
                }

                dp[w][pos] = value;
            }
        }

        return dp[W][0];
    }
};

// Memomization
class SolutionMEM
{
    int knapSack(int W, int pos, int wt[], int val[], int n, vector<vector<int>> &dp)
    {
        // Base Case
        if (W == 0 || pos == n)
        {
            return 0;
        }
        if (dp[W - 1][pos] != -1)
        {
            return dp[W - 1][pos];
        }

        // Leave
        int value = knapSack(W, pos + 1, wt, val, n, dp);

        // Take
        if (W - wt[pos] >= 0)
        {
            value = max(value, knapSack(W - wt[pos], pos + 1, wt, val, n, dp) + val[pos]);
        }

        return dp[W - 1][pos] = value;
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(W, vector<int>(n, -1));
        return knapSack(W, 0, wt, val, n, dp);
    }
};

// Recursive Method
class SolutionREC
{
    int knapSack(int W, int pos, int wt[], int val[], int n)
    {
        // Base Case
        if (W == 0 || pos == n)
        {
            return 0;
        }

        // Leave
        int value = knapSack(W, pos + 1, wt, val, n);

        // Take
        if (W - wt[pos] >= 0)
        {
            value = max(value, knapSack(W - wt[pos], pos + 1, wt, val, n) + val[pos]);
        }

        return value;
    }

public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {

        return knapSack(W, 0, wt, val, n);
    }
};