// https://leetcode.com/problems/maximum-product-subarray/description/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // PREFIX AND SUFFIX PRODUCT
    int maxProduct(vector<int> &nums)
    {
        // FOR EDGE CASE [0,10,10,10,10,10,10,10,10,10,-10,10,10,10,10,10,10,10,10,10,0]
        // Long Long doesn't work --> DO DOUBLE and typecase to INT on RETURNING.
        double pref = nums[0];
        double suff = nums[nums.size() - 1];
        double total_max = max(pref, suff);

        for (int i = 1; i < nums.size(); i++)
        {
            // IN CASE OF 0 --> TURN IT TO 1 (NEW SUB-PROBLEM)
            if (pref == 0)
            {
                pref = 1;
            }
            if (suff == 0)
            {
                suff = 1;
            }

            // UPDATE PRODUCTS
            pref *= nums[i];
            suff *= nums[nums.size() - 1 - i];
            total_max = max(total_max, max(pref, suff));
        }

        return (int)total_max;
    }
};