// https://leetcode.com/problems/minimum-common-value/?envType=daily-question&envId=2024-03-09

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {

        // Optimise Input/Output Performance by disabling synchornisation btw C and C++.
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                return nums1[i];
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }

        return -1;
    }
};