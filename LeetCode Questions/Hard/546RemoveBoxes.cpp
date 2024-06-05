// https://leetcode.com/problems/remove-boxes/description/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    int removeBoxes(int l, int r, int streak, vector<vector<vector<int>>> &dp, vector<int> &boxes)
    {
        // Base Case
        if (l > r)
        {
            return 0;
        }
        // Check in Memomization Table
        if (dp[l][r][streak] != -1)
        {
            return dp[l][r][streak];
        }

        int initialL = l;
        int initialStreak = streak;

        while (l + 1 <= r && boxes[l] == boxes[l + 1])
        {
            l++, streak++;
        }

        // Last Element Also Included so K+1
        int ans = (streak + 1) * (streak + 1) + removeBoxes(l + 1, r, 0, dp, boxes);

        for (int i = l + 1; i <= r; i++)
        {
            if (boxes[l] == boxes[i])   
            {
                // Left Part and Right Part
                ans = max(ans, removeBoxes(l + 1, i - 1, 0, dp, boxes) + removeBoxes(i, r, streak + 1, dp, boxes));
            }
        }

        return dp[initialL][r][initialStreak] = ans;
    }

public:
    int removeBoxes(vector<int> &boxes)
    {
        // 3D DP
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, -1)));

        // Helper Function
        return removeBoxes(0, boxes.size() - 1, 0, dp, boxes);
    }
};