// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#include <iostream>
using namespace std;
#include <climits>

class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (n > m)
        {
            return kthElement(arr2, arr1, m, n, k);
        }

        // Binary Search on Distance on Arr1
        int l = max(0, k - m), r = min(n, k);
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int mid2 = k - mid;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            if (mid < n)
            {
                r1 = arr1[mid];
            }
            if (mid2 < m)
            {
                r2 = arr2[mid2];
            }
            if (mid - 1 >= 0)
            {
                l1 = arr1[mid - 1];
            }
            if (mid2 - 1 >= 0)
            {
                l2 = arr2[mid2 - 1];
            }

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
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