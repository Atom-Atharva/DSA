// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=daily-question&envId=2023-12-12

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Time Complexity : O(n)
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int largest = 0;
        int second = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                second = largest;
                largest = nums[i];
                continue;
            }
            if (nums[i] >= second)
            {
                second = nums[i];
            }
        }

        return ((largest - 1) * (second - 1));
    }
};

// Time Complexity : O(nlogn)
// class Solution
// {
// public:
//     int maxProduct(vector<int> &nums)
//     {
//         // Sort Array in Desc
//         sort(nums.begin(), nums.end(), greater<int>());

//         return ((nums[0] - 1) * (nums[1] - 1));
//     }
// };