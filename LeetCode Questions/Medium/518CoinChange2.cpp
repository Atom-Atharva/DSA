// https://leetcode.com/problems/coin-change-ii/

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

#include <iostream>
using namespace std;
#include <vector>

// Method 3: Dynamic Programming
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

        // Fill Initial Cell--
        dp[0][0] = 1;

        // Fill First Row--
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        // Fill First Column--
        for (int i = 1; i < amount + 1; i++)
        {
            dp[0][i] = 0;
        }

        // Fill Rest of Cells--
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                int take = 0;
                if (j - coins[i - 1] >= 0)
                {
                    take = dp[i][j - coins[i - 1]];
                }
                int refuse = dp[i - 1][j];

                dp[i][j] = take + refuse;
            }
        }

        return dp[n][amount];
    }
};

// Method 2: Memomization
// class Solution
// {
//     int change(int amount, vector<int> &coins, int pos, vector<vector<int>> &dp)
//     {
//         // Base Case--
//         if (amount == 0)
//         {
//             return 1;
//         }
//         if (amount < 0 || pos == coins.size())
//         {
//             return 0;
//         }
//         if (dp[pos][amount] != -1)
//         {
//             return dp[pos][amount];
//         }

//         // Recursive Call--
//         int take = change(amount - coins[pos], coins, pos, dp);
//         int refuse = change(amount, coins, pos + 1, dp);

//         return dp[pos][amount] = take + refuse;
//     }

// public:
//     int change(int amount, vector<int> &coins)
//     {
//         vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

//         return change(amount, coins, 0, dp);
//     }
// };

// Method 1: Recursion
// class Solution
// {
//     int change(int amount, vector<int> &coins, int pos)
//     {
//         // Base Case--
//         if (amount == 0)
//         {
//             return 1;
//         }
//         if (amount < 0 || pos == coins.size())
//         {
//             return 0;
//         }

//         // Recursive Call--
//         int take = change(amount - coins[pos], coins, pos);
//         int refuse = change(amount, coins, pos + 1);

//         return take + refuse;
//     }

// public:
//     int change(int amount, vector<int> &coins)
//     {
//         return change(amount, coins, 0);
//     }
// };