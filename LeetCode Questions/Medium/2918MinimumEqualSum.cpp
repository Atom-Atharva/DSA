// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        int zeros1 = 0, zeros2 = 0;
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == 0)
            {
                zeros1++;
            }
            sum1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums2[i] == 0)
            {
                zeros2++;
            }
            sum2 += nums2[i];
        }

        if (zeros1 == 0 && zeros2 == 0)
        {
            return (sum1 == sum2) ? sum1 : -1;
        }
        // if (zeros1 == 0 || zeros2 == 0)
        // {
        //     return -1;
        // }

        long long max1 = sum1 + zeros1;
        long long max2 = sum2 + zeros2;

        if (max1 > max2)
        {
            if (max1 - sum2 > 0 && zeros2 == 0)
            {
                return -1;
            }
            return max1;
        }
        else
        {
            if (max2 - sum1 > 0 && zeros1 == 0)
            {
                return -1;
            }
            return max2;
        }
    }
};