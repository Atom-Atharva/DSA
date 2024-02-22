// https://leetcode.com/problems/permutation-sequence/description/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    int factorial(int n)
    {
        // Base Case
        if (n == 0 || n == 1)
        {
            return 1;
        }

        return factorial(n - 1) * n;
    }

    string getPermutation(int n, int k, vector<int> &nums)
    {
        // Base Case
        if (n == 0)
        {
            return "";
        }

        int fact = factorial(n - 1);
        int index = k / fact;

        string first = "";
        for (int i = 0; i < nums.size(); i++)
        {
            // Not Available
            if (nums[i] == 0)
            {
                continue;
            }

            // Set First Element
            if (index == 0)
            {
                first = to_string(i + 1);
                nums[i] = 0;
                break;
            }
            index--;
        }

        // Call Recursion
        k = k % fact;
        return first + getPermutation(n - 1, k, nums);
    }

public:
    string getPermutation(int n, int k)
    {
        vector<int> nums(n, 1);

        // k-1 --> 0 Indexing
        return getPermutation(n, k - 1, nums);
    }
};