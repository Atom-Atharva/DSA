// https://practice.geeksforgeeks.org/problems/word-wrap1646/1

// Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
// Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one.

// You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <climits>

// Method 3: Dynamic Programming
class Solution
{
public:
    int solveWordWrap(vector<int> nums, int k)
    {
        int n = nums.size();

        // Dynamic Array--
        vector<int> dp(n, -1);

        // Fill initial Cell--
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            int val = 0;
            int min_cost = INT_MAX;
            for (int j = i; j < n; j++)
            {
                val = val + nums[j];
                int gap = j - i;

                if (val + gap <= k && j < nums.size() - 1)
                {
                    // Recursive Call--
                    int cost = pow(k - (val + gap), 2) + dp[j + 1];

                    // Update Min Cost--
                    min_cost = min(min_cost, cost);
                }
                else if (val + gap <= k && j == nums.size() - 1)
                {
                    dp[i] = 0;
                }
                if (dp[i] != 0)
                {
                    dp[i] = min_cost;
                }
            }
        }
        return dp[0];
    }
};

// Method 2: Memomization
class Solution
{
    int solveWordWrap(vector<int> nums, int k, int pos, vector<int> &dp)
    {
        // Base Case--
        if (pos == nums.size())
        {
            return 0;
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        // Recursive Call--
        int val = 0;

        int min_cost = INT_MAX;
        for (int i = pos; i < nums.size(); i++)
        {
            // Update Line--
            val = val + nums[i];
            int gap = i - pos;

            if (val + gap <= k && i < nums.size() - 1)
            {
                // Recursive Call--
                int cost = pow(k - (val + gap), 2) + solveWordWrap(nums, k, i + 1, dp);

                // Update Min Cost--
                min_cost = min(min_cost, cost);
            }
            else if (val + gap <= k && i == nums.size() - 1)
            {
                return dp[pos] = 0;
            }
        }

        return dp[pos] = min_cost;
    }

public:
    int solveWordWrap(vector<int> nums, int k)
    {
        vector<int> dp(nums.size(), -1);

        // Helper Function--
        return solveWordWrap(nums, k, 0, dp);
    }
};

// Method 1: Recursion
class Solution
{
    int solveWordWrap(vector<int> nums, int k, int pos, vector<int> &line)
    {
        // Base Case--
        if (pos == nums.size())
        {
            int cost = 0;
            for (int i = 0; i < line.size() - 1; i++)
            {
                cost += pow((k - line[i]), 2);
            }

            return cost;
        }

        // Recursive Call--
        line.push_back(0);
        int lastPost = line.size() - 1;

        int min_cost = INT_MAX;
        for (int i = pos; i < nums.size(); i++)
        {
            // Update Line--
            line[lastPost] += nums[i];
            if (i > pos)
            {
                line[lastPost]++;
            }

            if (line[lastPost] > k)
            {
                break;
            }

            // Recursive Call--
            int cost = solveWordWrap(nums, k, i + 1, line);

            // Update Min Cost--
            min_cost = min(min_cost, cost);
        }

        // Return minimum cost--
        line.pop_back();
        return min_cost;
    }

public:
    int solveWordWrap(vector<int> nums, int k)
    {
        // Line--
        vector<int> line;

        // Helper Function--
        return solveWordWrap(nums, k, 0, line);
    }
};