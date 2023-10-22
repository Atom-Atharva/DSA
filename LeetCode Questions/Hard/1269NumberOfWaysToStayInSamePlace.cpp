// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/?envType=daily-question&envId=2023-10-15

// You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

// Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

#include <iostream>
#include <climits>
using namespace std;

#define M 1000000007

// Method 2: Memomization Approach
class Solution
{
    int numWays(int steps, int arrLen, int pos, int **dp)
    {
        // Base Case--
        if (pos == -1 || pos == arrLen)
        {
            return INT_MIN;
        }
        if (steps == 0)
        {
            return (pos == 0) ? 1 : INT_MIN;
        }
        if (dp[steps][pos] != -1)
        {
            return dp[steps][pos];
        }

        // Recursive Calls--
        int left = numWays(steps - 1, arrLen, pos - 1, dp);
        left = (left < 0) ? 0 : left;
        int right = numWays(steps - 1, arrLen, pos + 1, dp);
        right = (right < 0) ? 0 : right;
        int stay = numWays(steps - 1, arrLen, pos, dp);
        stay = (stay < 0) ? 0 : stay;

        int ans = ((long long)left + right + stay) % M;

        return dp[steps][pos] = ans;
    }

public:
    int numWays(int steps, int arrLen)
    {
        int **dp = new int *[steps + 1];
        for (int i = 0; i < steps + 1; i++)
        {
            int size = min(arrLen, steps);
            dp[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                dp[i][j] = -1;
            }
        }

        return numWays(steps, arrLen, 0, dp);
    }
};

// Method 1:  Recursive Approach
// Time Limit Exceeded.
// class Solution
// {
// public:
//     int numWays(int steps, int arrLen, int pos = 0)
//     {
//         // Base Case--
//         if (pos == -1 || pos == arrLen)
//         {
//             return INT_MIN;
//         }
//         if (steps == 0)
//         {
//             return (pos == 0) ? 1 : INT_MIN;
//         }

//         // Recursive Calls--
//         int left = numWays(steps - 1, arrLen, pos - 1);
//         left = (left < 0) ? 0 : left;
//         int right = numWays(steps - 1, arrLen, pos + 1);
//         right = (right < 0) ? 0 : right;
//         int stay = numWays(steps - 1, arrLen, pos);
//         stay = (stay < 0) ? 0 : stay;

//         int ans = ((long long)left + right + stay) % M;

//         return ans;
//     }
// };