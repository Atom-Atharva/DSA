// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1

// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        // Base Case--
        if (n == 1)
        {
            return {1};
        }

        // Right Product and Left Product--
        long long rPro = 1;
        long long lPro = 1;

        vector<long long> right(n);
        vector<long long> left(n);

        for (int i = 0; i < n; i++)
        {
            left[i] = nums[i] * lPro;
            lPro *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = nums[i] * rPro;
            rPro *= nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            // Handle Edge Cases--
            if (i == 0)
            {
                nums[i] = right[i + 1];
                continue;
            }
            if (i == n - 1)
            {
                nums[i] = left[i - 1];
                continue;
            }

            // Right Product * left Product--
            nums[i] = left[i - 1] * right[i + 1];
        }

        // Return ans--
        return nums;
    }
};