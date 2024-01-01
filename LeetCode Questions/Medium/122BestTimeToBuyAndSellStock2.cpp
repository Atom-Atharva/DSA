// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Easy Approach--
// Profit Add--
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

// Memomization Approach--
class Solution
{
    int maxProfit(vector<int> &prices, int pos, vector<int> &dp)
    {
        // Base Case--
        if (pos >= prices.size())
        {
            return 0;
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        int maxPro = 0;
        int currPro = 0;
        int buySto = INT_MAX;
        // Find Any Profit
        for (int i = pos; i < prices.size(); i++)
        {
            currPro = prices[i] - buySto;
            // Call Recursion on later days
            if (currPro < 0)
            {
                buySto = prices[i];
            }
            else
            {
                int laterProfit = maxProfit(prices, i + 1, dp);
                maxPro = max(maxPro, laterProfit + currPro);
            }
        }

        return dp[pos] = maxPro;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> dp(prices.size(), -1);

        return maxProfit(prices, 0, dp);
    }
};

// Recursive Approach--
class Solution
{
public:
    int maxProfit(vector<int> &prices, int pos = 0)
    {
        // Base Case--
        if (pos >= prices.size())
        {
            return 0;
        }

        int maxPro = 0;
        int currPro = 0;
        int buySto = INT_MAX;
        // Find Any Profit
        for (int i = pos; i < prices.size(); i++)
        {
            currPro = prices[i] - buySto;
            // Call Recursion on later days
            if (currPro < 0)
            {
                buySto = prices[i];
            }
            else
            {
                int laterProfit = maxProfit(prices, i + 1);
                maxPro = max(maxPro, laterProfit + currPro);
            }
        }

        return maxPro;
    }
};