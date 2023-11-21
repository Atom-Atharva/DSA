// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/?envType=daily-question&envId=2023-11-19

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

// Sort--
class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());

        int count = 0;
        int largest = nums[0];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (largest > nums[i])
            {
                ans += count;
                largest = nums[i];
            }
            count++;
        }

        return ans;
    }
};

// Priority Queue--
// class Solution
// {
// public:
//     int reductionOperations(vector<int> &nums)
//     {
//         priority_queue<int> pque;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             pque.push(nums[i]);
//         }

//         int count = 0;
//         int largest = pque.top();
//         int ans = 0;
//         while (!pque.empty())
//         {
//             if (largest > pque.top())
//             {
//                 ans += count;
//                 largest = pque.top();
//             }
//             count++;
//             pque.pop();
//         }

//         return ans;
//     }
// };