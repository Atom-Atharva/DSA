// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/?envType=daily-question&envId=2023-11-18

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

//************************* GOOD QUESTION ***********************************//

// Sliding Window Problem--
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int l = 0, r = 0;
        int elements = 0;
        long long actual_sum = nums[0];
        while (r < nums.size())
        {
            long long expected_sum = (long long)nums[r] * (r - l + 1); // [2 2 2 2] --> 2 * 4 == 8;

            if (expected_sum > actual_sum + k)
            {
                actual_sum -= nums[l];
                l++;
                continue;
            }

            elements = max(elements, r - l + 1);
            r++;
            if (r == nums.size())
            {
                break;
            }
            actual_sum += nums[r];
        }

        return elements;
    }
};

// TLE - Brute Force Method
// class Solution
// {
// public:
//     int maxFrequency(vector<int> &nums, int k)
//     {
//         // Sort Array--
//         sort(nums.begin(), nums.end());

//         // Calculate Maximum Elements to be changed--
//         int elements = 0;
//         for (int i = nums.size() - 1; i > 0; i--)
//         {
//             // Calculate Maximum Elements within k to be changed--
//             int freq = 1;
//             int op = k;
//             for (int j = i - 1; j >= 0; j--)
//             {
//                 if (nums[i] - nums[j] <= op)
//                 {
//                     op = op - (nums[i] - nums[j]);
//                     freq++;
//                 }
//             }
//             elements = max(elements, freq);
//         }

//         return elements;
//     }
// };