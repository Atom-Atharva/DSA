// https://leetcode.com/problems/intersection-of-two-arrays/?envType=daily-question&envId=2024-03-10

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ele(1001, 0);

        for (int i = 0; i < nums1.size(); i++)
        {
            ele[nums1[i]]++;
        }

        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (ele[nums2[i]])
            {
                ele[nums2[i]] = 0;
                ans.push_back(nums2[i]);
            }
        }

        return ans;
    }
};