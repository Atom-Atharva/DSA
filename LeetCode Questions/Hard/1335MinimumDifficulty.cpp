// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/?envType=daily-question&envId=2023-12-29

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Memomization Table--
class Solution
{
    int minDifficulty(vector<int> &jobDifficulty, int d, int pos, vector<vector<int>> &dp)
    {
        // Reject Case--
        if (d > jobDifficulty.size())
        {
            return -1;
        }

        // Base Case--
        if (d == 0 && pos == jobDifficulty.size())
        {
            return 0;
        }
        if (d == 0 || pos == jobDifficulty.size())
        {
            return -1;
        }

        // If Exist--
        if (dp[pos][d] != -1)
        {
            return dp[pos][d];
        }

        // Partitions--
        int minDiff = INT_MAX;
        int currDay = jobDifficulty[pos];
        for (int i = pos; i < jobDifficulty.size(); i++)
        {
            currDay = max(currDay, jobDifficulty[i]);

            int nextDays = minDifficulty(jobDifficulty, d - 1, i + 1, dp);
            if (nextDays == -1)
            {
                continue;
            }
            int totalDiff = currDay + nextDays;
            minDiff = min(minDiff, totalDiff);
        }

        return dp[pos][d] = (minDiff == INT_MAX) ? -1 : minDiff;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d + 1, -1));

        return minDifficulty(jobDifficulty, d, 0, dp);
    }
};

// Recursive Approach--
// class Solution
// {
// public:
//     int minDifficulty(vector<int> &jobDifficulty, int d, int pos = 0)
//     {
//         // Reject Case--
//         if (d > jobDifficulty.size())
//         {
//             return -1;
//         }

//         // Base Case--
//         if (d == 0 && pos == jobDifficulty.size())
//         {
//             return 0;
//         }
//         if (d == 0 || pos == jobDifficulty.size())
//         {
//             return -1;
//         }

//         // Partitions--
//         int minDiff = INT_MAX;
//         int currDay = jobDifficulty[pos];
//         for (int i = pos; i < jobDifficulty.size(); i++)
//         {
//             currDay = max(currDay, jobDifficulty[i]);

//             int nextDays = minDifficulty(jobDifficulty, d - 1, i + 1);
//             if (nextDays == -1)
//             {
//                 continue;
//             }
//             int totalDiff = currDay + nextDays;
//             minDiff = min(minDiff, totalDiff);
//         }

//         return (minDiff == INT_MAX) ? -1 : minDiff;
//     }
// };