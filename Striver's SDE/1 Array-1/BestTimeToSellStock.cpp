// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - buy;
            if (profit < 0)
            {
                buy = prices[i];
            }
            else
            {
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};