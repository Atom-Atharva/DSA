// https://www.geeksforgeeks.org/problems/cutted-segments1642/1

#include <iostream>
using namespace std;
#include <climits>
#include <vector>

// Dynamic Programming
class Solution
{
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Dynamic Array
        vector<int> dp(n + 1);

        // Initial Cell
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int numX = (i - x >= 0) ? dp[i - x] : INT_MIN;
            int numY = (i - y >= 0) ? dp[i - y] : INT_MIN;
            int numZ = (i - z >= 0) ? dp[i - z] : INT_MIN;

            int cuts = max(numX, max(numY, numZ));

            dp[i] = (cuts != INT_MIN) ? cuts + 1 : INT_MIN;
        }

        return (dp[n] == INT_MIN) ? 0 : dp[n];
    }
};

// Memomization
class Solution
{
    // Function to find the maximum number of cuts.
    int maximizeTheCutsHelper(int n, int x, int y, int z, vector<int> &dp)
    {
        // Base Case
        if (n == 0)
        {
            return 0;
        }
        if (n < 0)
        {
            return INT_MIN;
        }
        if (dp[n - 1] != -1)
        {
            return dp[n - 1];
        }

        // Recursive Calls
        int numX = maximizeTheCutsHelper(n - x, x, y, z, dp);
        int numY = maximizeTheCutsHelper(n - y, x, y, z, dp);
        int numZ = maximizeTheCutsHelper(n - z, x, y, z, dp);

        int cuts = max(numX, max(numY, numZ));

        return dp[n - 1] = (cuts == INT_MIN) ? INT_MIN : cuts + 1;
    }

public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n, -1);
        int cuts = maximizeTheCutsHelper(n, x, y, z, dp);
        return (cuts == INT_MIN) ? 0 : cuts;
    }
};

// Recursive Approach
class Solution
{
    // Function to find the maximum number of cuts.
    int maximizeTheCutsHelper(int n, int x, int y, int z)
    {
        // Base Case
        if (n == 0)
        {
            return 0;
        }
        if (n < 0)
        {
            return INT_MIN;
        }

        // Recursive Calls
        int numX = maximizeTheCutsHelper(n - x, x, y, z);
        int numY = maximizeTheCutsHelper(n - y, x, y, z);
        int numZ = maximizeTheCutsHelper(n - z, x, y, z);

        int cuts = max(numX, max(numY, numZ));

        return (cuts == INT_MIN) ? INT_MIN : cuts + 1;
    }

public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int cuts = maximizeTheCutsHelper(n, x, y, z);
        return (cuts == INT_MIN) ? 0 : cuts;
    }
};