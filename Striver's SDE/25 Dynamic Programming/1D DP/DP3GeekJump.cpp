// https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        int oneStep = 0;
        int twoStep = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            int minStep = oneStep + abs(height[i] - height[i + 1]);
            if (i + 2 <= n - 1)
            {
                minStep = min(minStep, twoStep + abs(height[i] - height[i + 2]));
            }
            twoStep = oneStep;
            oneStep = minStep;
        }

        return oneStep;
    }
};

class SolutionTAB
{
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n, 0);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            int minStep = dp[i + 1] + abs(height[i] - height[i + 1]);
            if (i + 2 <= n - 1)
            {
                minStep = min(minStep, dp[i + 2] + abs(height[i] - height[i + 2]));
            }
            dp[i] = minStep;
        }

        return dp[0];
    }
};

// Memomization
class SolutionMEM
{
    int minimumEnergy(vector<int> &height, int n, int pos, vector<int> &dp)
    {
        // Base Case
        if (pos == n - 1)
        {
            return 0;
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        int minStep = minimumEnergy(height, n, pos + 1, dp) + abs(height[pos] - height[pos + 1]);
        if (pos + 2 <= n - 1)
        {
            minStep = min(minStep, minimumEnergy(height, n, pos + 2, dp) + abs(height[pos] - height[pos + 2]));
        }
        return dp[pos] = minStep;
    }

public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n, -1);
        return minimumEnergy(height, n, 0, dp);
    }
};