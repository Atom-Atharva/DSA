// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

// Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.

#include <iostream>
using namespace std;
#include <vector>

// Method 3: Dynamic Programming
class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n + 1);

        // Initialize DP
        dp[0] = 0;
        dp[1] = arr[0];

        // Fill Cells--
        for (int i = 2; i <= n; i++)
        {
            int take = arr[i - 1] + dp[i - 2];
            int refuse = dp[i - 1];

            dp[i] = max(take, refuse);
        }

        return dp[n];
    }
};

// Method 2: Memomization
class Solution
{
    int findMaxSum(int arr[], int n, int pos, vector<int> &dp)
    {
        // Base Case--
        if (pos >= n)
        {
            return 0;
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        // Recursion Call--
        int take = arr[pos] + findMaxSum(arr, n, pos + 2, dp);
        int refuse = findMaxSum(arr, n, pos + 1, dp);

        // Calculate Maximum--
        return dp[pos] = max(take, refuse);
    }

public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n + 1, -1);
        return findMaxSum(arr, n, 0, dp);
    }
};

// Method 1: Recursion
// !TLE
class Solution
{
    int findMaxSum(int arr[], int n, int pos)
    {
        // Base Case--
        if (pos >= n)
        {
            return 0;
        }

        // Recursion Call--
        int take = arr[pos] + findMaxSum(arr, n, pos + 2);
        int refuse = findMaxSum(arr, n, pos + 1);

        // Calculate Maximum--
        return max(take, refuse);
    }

public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        return findMaxSum(arr, n, 0);
    }
};