// https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minimizeCost(vector<int> &arr, int &k)
    {
        vector<int> dp(arr.size(), 0);
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            int minStep = dp[i + 1] + abs(arr[i] - arr[i + 1]);
            for (int j = 2; j <= k && i + j < arr.size(); j++)
            {
                minStep = min(minStep, dp[i + j] + abs(arr[i] - arr[i + j]));
            }

            dp[i] = minStep;
        }

        return dp[0];
    }
};

class SolutionMEM
{
    int minimizeCost(vector<int> &arr, int &k, int pos, vector<int> &dp)
    {
        // Base Case
        if (pos == arr.size() - 1)
        {
            return 0;
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        int minStep = minimizeCost(arr, k, pos + 1, dp) + abs(arr[pos] - arr[pos + 1]);
        for (int i = 2; i <= k && pos + i < arr.size(); i++)
        {
            minStep = min(minStep, minimizeCost(arr, k, pos + i, dp) + abs(arr[pos] - arr[pos + i]));
        }

        return dp[pos] = minStep;
    }

public:
    int minimizeCost(vector<int> &arr, int &k)
    {
        vector<int> dp(arr.size(), -1);
        return minimizeCost(arr, k, 0, dp);
    }
};
