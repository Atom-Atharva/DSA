// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        stack<int> stk;
        stk.push(0);

        vector<int> answer(prices.size());
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            // GET SMALLER TOP
            while (stk.top() > prices[i])
            {
                stk.pop();
            }
            answer[i] = prices[i] - stk.top();

            // INSERT CURRENT
            stk.push(prices[i]);
        }

        return answer;
    }
};