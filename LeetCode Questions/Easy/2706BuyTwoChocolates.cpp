// https://leetcode.com/problems/buy-two-chocolates/description/?envType=daily-question&envId=2023-12-20

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        // Sort Array--
        sort(prices.begin(), prices.end());

        // First Two--
        return (prices[0] + prices[1] <= money) ? money - prices[0] - prices[1] : money;
    }
};