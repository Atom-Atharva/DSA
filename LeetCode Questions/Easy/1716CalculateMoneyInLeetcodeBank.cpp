// https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2023-12-06

#include <iostream>
using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {
        int st = 0;
        int money = 1;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            // Every Monday Update--
            if (i % 7 == 0)
            {
                st++;
                money = st;
            }

            total += money;
            money++;
        }

        return total;
    }
};