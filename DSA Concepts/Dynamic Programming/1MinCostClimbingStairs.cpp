// https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
using namespace std;
#include <vector>

// Space Optimization
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost, int N)
    {
        int next1 = 0;
        int next2 = 0;

        for (int i = cost.size() - 1; i >= 0; i--)
        {
            int curr = cost[i] + min(next1, next2);

            next2 = next1;
            next1 = curr;
        }

        return min(next1, next2);
    }
};

// Dynamic Programming
class SolutionTAB
{
public:
    int minCostClimbingStairs(vector<int> &cost, int N)
    {
        vector<int> dp(cost.size() + 2, 0);

        for (int i = cost.size() - 1; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }

        return min(dp[0], dp[1]);
    }
};

// Memomization
class SolutionMEM
{
    int minCostClimbingStairs(vector<int> &cost, int N, int pos, vector<int> &dp)
    {
        // Base Case
        if (pos >= N)
        {
            return 0;
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        // Take 1 or 2 Steps
        int one = minCostClimbingStairs(cost, N, pos + 1, dp);
        int two = minCostClimbingStairs(cost, N, pos + 2, dp);

        return dp[pos] = min(one, two) + cost[pos];
    }

public:
    int minCostClimbingStairs(vector<int> &cost, int N)
    {
        vector<int> dp(cost.size(), -1);
        return min(minCostClimbingStairs(cost, N, 0, dp), minCostClimbingStairs(cost, N, 1, dp));
    }
};

// Recursion
class SolutionREC
{
    int minCostClimbingStairs(vector<int> &cost, int N, int pos)
    {
        // Base Case
        if (pos >= N)
        {
            return 0;
        }

        // Take 1 or 2 Steps
        int one = minCostClimbingStairs(cost, N, pos + 1);
        int two = minCostClimbingStairs(cost, N, pos + 2);

        return min(one, two) + cost[pos];
    }

public:
    int minCostClimbingStairs(vector<int> &cost, int N)
    {
        return min(minCostClimbingStairs(cost, N, 0), minCostClimbingStairs(cost, N, 1));
    }
};