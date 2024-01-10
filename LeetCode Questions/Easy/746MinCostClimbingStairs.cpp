// https://leetcode.com/problems/min-cost-climbing-stairs/description/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Space Optimization--
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        int prev1 = 0;
        int prev2 = 0;

        for (int i = 2; i <= n; i++)
        {
            int curr = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

// Dynamic Programming--
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        vector<int> dp(n + 1);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};

// Memomization Approach--
class Solution
{
    int minCostClimbingStairs(vector<int> &cost, int pos, vector<int> &dp)
    {
        // Base Case--
        if (pos == cost.size())
        {
            return 0;
        }
        if (pos > cost.size())
        {
            return INT_MAX;
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        // Recursive Calls--
        int step1 = minCostClimbingStairs(cost, pos + 1, dp);
        int step2 = minCostClimbingStairs(cost, pos + 2, dp);

        return dp[pos] = cost[pos] + min(step1, step2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size(), -1);

        return min(minCostClimbingStairs(cost, 0, dp), minCostClimbingStairs(cost, 1, dp));
    }
};

// Recursive Approach--
class Solution
{
    int minCostClimbingStairs(vector<int> &cost, int pos)
    {
        // Base Case--
        if (pos == cost.size())
        {
            return 0;
        }
        if (pos > cost.size())
        {
            return INT_MAX;
        }

        // Recursive Calls--
        int step1 = minCostClimbingStairs(cost, pos + 1);
        int step2 = minCostClimbingStairs(cost, pos + 2);

        return cost[pos] + min(step1, step2);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        return min(minCostClimbingStairs(cost, 0), minCostClimbingStairs(cost, 1));
    }
};