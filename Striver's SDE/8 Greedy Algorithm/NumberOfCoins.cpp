// https://www.geeksforgeeks.org/problems/number-of-coins1824/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minCoins(vector<int> &coins, int M, int V)
    {
        sort(coins.begin(), coins.end(), greater<int>());

        int coin = 0;
        for (int i = 0; i < M; i++)
        {
            if (V >= coins[i])
            {
                int curr = V / coins[i];
                int value = curr * coins[i];

                coin += curr;
                V -= value;
            }
        }

        return (V == 0) ? coin : -1;
    }
};