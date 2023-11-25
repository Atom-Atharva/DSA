// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/?envType=daily-question&envId=2023-11-24

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        // SORT--
        sort(piles.begin(), piles.end(), greater<int>());

        // Two Pointers--
        int st = 1, en = piles.size() - 1;
        int sum = 0;
        while (st < en)
        {
            sum += piles[st];
            st += 2;
            en--;
        }

        return sum;
    }
};
