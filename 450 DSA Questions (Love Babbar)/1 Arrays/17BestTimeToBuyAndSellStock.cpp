// https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_893405

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <iostream>
using namespace std;
#include <vector>

int maximumProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int profit = 0;
    int buy = prices[0];

    for (int i = 0; i < prices.size(); i++)
    {
        profit = prices[i] - buy;

        if (maxProfit < profit)
        {
            maxProfit = profit;
        }
        if (profit < 0)
        {
            buy = prices[i];
            profit = 0;
        }
    }
    return maxProfit;
}