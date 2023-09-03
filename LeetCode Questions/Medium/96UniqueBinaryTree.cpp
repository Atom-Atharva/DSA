// https://leetcode.com/problems/unique-binary-search-trees/description/

// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

//****************************** IMPORTANT QUESTION *************************************//

#include <iostream>
using namespace std;

// *************************** Catalan Number : ((2n)!/(n+1)!n!) *************************** //
// https://www.geeksforgeeks.org/program-nth-catalan-number/

// Method 3: Dynamic Programming--
class Solution
{
public:
    int numTrees(int n)
    {
        // Dynamic Array--
        int *arr = new int[n + 1];

        // Fill Initial Cell--
        arr[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            int res = 0;
            for (int j = 0; j < i; j++)
            {
                res += arr[j] * arr[i - j - 1];
            }
            arr[i] = res;
        }

        return arr[n];
    }
};

// Method 2: Memomization--
class Solution
{
    int numTrees(int n, int *arr)
    {
        // Base Case--
        if (n == 0)
        {
            return 1;
        }
        if (arr[n - 1] != -1)
        {
            return arr[n - 1];
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            // ************* RECURSIVE FORMULA : Cn = SUM i->0 to n(Ci * Cn-i) *********** //
            res += numTrees(i, arr) * numTrees(n - i - 1, arr);
        }

        return arr[n - 1] = res;
    }

public:
    int numTrees(int n)
    {
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = -1;
        }

        return numTrees(n, arr);
    }
};

// Method 1: Recursion--
class Solution
{
public:
    int numTrees(int n)
    {
        // Base Case--
        if (n == 0)
        {
            return 1;
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            // ************* RECURSIVE FORMULA : Cn = SUM i->0 to n(Ci * Cn-i) *********** //
            res += numTrees(i) * numTrees(n - i - 1);
        }

        return res;
    }
};