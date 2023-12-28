// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/?envType=daily-question&envId=2023-12-26

#include <iostream>
using namespace std;
#include <vector>

// Dynamic Programming--
class Solution
{
    int M = 1e9 + 7;

public:
    int numRollsToTarget(int n, int k, int target)
    {
        // DP Table--
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));

        // Filling Initial Cell--
        dp[0][0] = 1;

        // Initialise Rows--
        for (int i = 1; i < n + 1; i++)
        {
            dp[i][0] = 0;
        }
        // Initialise Cols--
        for (int i = 1; i < target + 1; i++)
        {
            dp[0][i] = 0;
        }

        // Fill Rest of Table--
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < target + 1; j++)
            {
                // Every Possible Way--
                int ways = 0;
                for (int l = 1; l <= k; l++)
                {
                    if (j - l < 0)
                    {
                        break;
                    }

                    ways = (ways + dp[i - 1][j - l]) % M;
                }

                dp[i][j] = ways;
            }
        }

        return dp[n][target];
    }
};

// Memomization Table--
// class Solution
// {
//     int M = 1e9 + 7;

//     int numRollsToTarget(int n, int k, int target, vector<vector<int>> &dp)
//     {
//         // Base Case--
//         if (n == 0 && target == 0)
//         {
//             return 1;
//         }
//         if (n == 0 || target <= 0)
//         {
//             return 0;
//         }
//         if (dp[n][target] != -1)
//         {
//             return dp[n][target];
//         }

//         // Many Reccursive Calls--
//         int ways = 0;
//         for (int i = 1; i <= k; i++)
//         {
//             ways = (ways + numRollsToTarget(n - 1, k, target - i, dp)) % M;
//         }

//         // Return Output--
//         return dp[n][target] = ways;
//     }

// public:
//     int numRollsToTarget(int n, int k, int target)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

//         return numRollsToTarget(n, k, target, dp);
//     }
// };

// Reccursive Method--
// class Solution
// {
//     int M = 1e9 + 7;

// public:
//     int numRollsToTarget(int n, int k, int target)
//     {
//         // Base Case--
//         if (n == 0 && target == 0)
//         {
//             return 1;
//         }
//         if (n == 0 || target <= 0)
//         {
//             return 0;
//         }

//         // Many Reccursive Calls--
//         int ways = 0;
//         for (int i = 1; i <= k; i++)
//         {
//             ways = (ways + numRollsToTarget(n - 1, k, target - i)) % M;
//         }

//         // Return Output--
//         return ways;
//     }
// };