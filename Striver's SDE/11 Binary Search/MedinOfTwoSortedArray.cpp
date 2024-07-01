// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Method 1: Merge 2 Sorted Arrays
// Method 2: Count till n/2 elements : POINTERS

// Method 3: Binary Search on LENGTH of ARRAY
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = (nums1.size() + nums2.size() + 1) / 2;

        // Binary Search on nums1 for Length between [0, nums1.size()]
        int l = 0, r = nums1.size();
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int mid2 = n - mid;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if (mid < nums1.size())
            {
                r1 = nums1[mid];
            }
            if (mid2 < nums2.size())
            {
                r2 = nums2[mid2];
            }
            if (mid - 1 >= 0)
            {
                l1 = nums1[mid - 1];
            }
            if (mid2 - 1 >= 0)
            {
                l2 = nums2[mid2 - 1];
            }

            if (l1 <= r2 && l2 <= r1)
            {
                if ((nums1.size() + nums2.size()) % 2 == 1)
                {
                    return max(l1, l2);
                }
                else
                {
                    return ((double(max(l1, l2)) + min(r1, r2)) / 2);
                }
            }
            else if (l1 > r2)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return 0;
    }
};