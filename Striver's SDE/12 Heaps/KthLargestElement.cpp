// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <iostream>
using namespace std;
#include <queue>
#include <vector>

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> queue;
        for (int i = 0; i < nums.size(); i++)
        {
            queue.push(nums[i]);
        }

        int element = queue.top();
        while (k--)
        {
            element = queue.top();
            queue.pop();
        }

        return element;
    }
};