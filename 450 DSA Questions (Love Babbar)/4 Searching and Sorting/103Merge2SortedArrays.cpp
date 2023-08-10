// https://leetcode.com/problems/merge-sorted-array/

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> ans(n + m);
        int k = 0;
        int i = 0, j = 0;

        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                ans[k] = nums1[i];
                i++;
            }
            else
            {
                ans[k] = nums2[j];
                j++;
            }
            k++;
        }

        for (int l = i; l < m; l++)
        {
            ans[k] = nums1[l];
            k++;
        }

        for (int l = j; l < n; l++)
        {
            ans[k] = nums2[l];
            k++;
        }

        for (int i = 0; i < n + m; i++)
        {
            nums1[i] = ans[i];
        }

        return;
    }
};