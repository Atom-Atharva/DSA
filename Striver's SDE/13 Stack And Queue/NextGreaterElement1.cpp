// https://leetcode.com/problems/next-greater-element-i/description/

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nextGreater(nums2.size(), -1);
        stack<int> stk;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!stk.empty())
            {
                if (stk.top() > nums2[i])
                {
                    nextGreater[i] = stk.top();
                    break;
                }
                stk.pop();
            }
            stk.push(nums2[i]);
        }

        vector<int> output(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    output[i] = nextGreater[j];
                }
            }
        }

        return output;
    }
};