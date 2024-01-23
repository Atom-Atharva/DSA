// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <iostream>
using namespace std;
#include <vector>

// Dynamic Programming--
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Dynamic Array--
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            int steal = 0;
            if (j - weight[i - 1] >= 0)
            {
                steal = value[i - 1] + dp[i - 1][j - weight[i - 1]];
            }
            int leave = dp[i - 1][j];

            dp[i][j] = max(steal, leave);
        }
    }

    return dp[n][maxWeight];
}

// Memomization--
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>> &dp)
{
    // Base Case--
    if (maxWeight == 0 || n == 0)
    {
        return 0;
    }

    if (dp[maxWeight][n] != -1)
    {
        return dp[maxWeight][n];
    }

    // Recursion Call--
    int steal = 0;
    if (maxWeight - weight[n - 1] >= 0)
    {
        steal = value[n - 1] + knapsack(weight, value, n - 1, maxWeight - weight[n - 1], dp);
    }
    int leave = knapsack(weight, value, n - 1, maxWeight, dp);

    return dp[maxWeight][n] = max(steal, leave);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Dynamic Array--
    vector<vector<int>> dp(maxWeight + 1, vector<int>(n + 1, -1));

    return knapsack(weight, value, n, maxWeight, dp);
}

// Recursive Approach
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Base Case--
    if (maxWeight == 0 || n == 0)
    {
        return 0;
    }

    // Recursion Call--
    int steal = 0;
    if (maxWeight - weight[n - 1] >= 0)
    {
        steal = value[n - 1] + knapsack(weight, value, n - 1, maxWeight - weight[n - 1]);
    }
    int leave = knapsack(weight, value, n - 1, maxWeight);

    return max(steal, leave);
}