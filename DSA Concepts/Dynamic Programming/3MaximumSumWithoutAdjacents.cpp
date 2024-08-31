// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1

#include <iostream>
using namespace std;
#include <vector>

//**** THIS QUESTION CAN BE DONE MORE OPTIMALLY *****//
//** BY MAKING STEPS LIKE pos+1(not taken) and pos+2(taken) **//

// Space Optimization
class Solution
{
public:
    int findMaxSum(int *arr, int n)
    {
        int nextT = 0, nextF = 0;
        for (int pos = n - 1; pos >= 0; pos--)
        {
            int currT = 0, currF = 0;
            for (int prev = 0; prev < 2; prev++)
            {
                // Leave
                int sum = nextF;

                // Take if Not Adj
                if (!prev)
                {
                    sum = max(sum, nextT + arr[pos]);
                }

                if (prev)
                {
                    currT = sum;
                }
                else
                {
                    currF = sum;
                }
            }
            nextT = currT;
            nextF = currF;
        }

        // For 0th Position with Initial prev: False
        return nextF;
    }
};

// Dynamic Programming
class SolutionTAB
{
public:
    int findMaxSum(int *arr, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int pos = n - 1; pos >= 0; pos--)
        {
            for (int prev = 0; prev < 2; prev++)
            {
                // Leave
                int sum = dp[pos + 1][0];

                // Take if Not Adj
                if (!prev)
                {
                    sum = max(sum, dp[pos + 1][1] + arr[pos]);
                }

                dp[pos][prev] = sum;
            }
        }

        // For 0th Position with Initial prev: False
        return dp[0][0];
    }
};

// Memomization
class SolutionMEM
{
    // Take OR DONT TAKE
    int findMaxSum(int *arr, int n, int pos, bool prev, vector<vector<int>> &dp)
    {
        // Base Case
        if (pos == n)
        {
            return 0;
        }
        if (dp[pos][prev] != -1)
        {
            return dp[pos][prev];
        }

        // Leave
        int sum = findMaxSum(arr, n, pos + 1, false, dp);

        // Take if Not Adj
        if (!prev)
        {
            sum = max(sum, findMaxSum(arr, n, pos + 1, true, dp) + arr[pos]);
        }

        return dp[pos][prev] = sum;
    }

public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findMaxSum(arr, n, 0, false, dp);
    }
};

// Recursion
class SolutionREC
{
    // Take OR DONT TAKE
    int findMaxSum(int *arr, int n, int pos, bool prev)
    {
        // Base Case
        if (pos == n)
        {
            return 0;
        }

        // Leave
        int sum = findMaxSum(arr, n, pos + 1, false);

        // Take if Not Adj
        if (!prev)
        {
            sum = max(sum, findMaxSum(arr, n, pos + 1, true) + arr[pos]);
        }

        return sum;
    }

public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        return findMaxSum(arr, n, 0, false);
    }
};