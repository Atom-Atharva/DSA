// https://leetcode.com/problems/kth-largest-element-in-an-array/

// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

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

        int top = 0;
        for (int i = 0; i < k; i++)
        {
            top = queue.top();
            queue.pop();
        }

        return top;
    }
};