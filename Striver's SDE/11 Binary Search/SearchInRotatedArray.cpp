// https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int search(int A[], int l, int h, int key)
    {
        // Find Pivot Point
        int st = l, en = h;
        while (st <= en)
        {
            int mid = (st + en) / 2;

            // Pivot Lies on Right Part
            if (A[mid] >= A[st] && A[mid] <= A[en])
            {
                break;
            }
            else if (A[mid] >= A[st] && A[mid] >= A[en])
            {
                st = mid + 1;
            }
            else if (A[mid] <= A[st] && A[mid] <= A[en])
            {
                en = mid;
            }
        }
        int pivot = st;

        // Search On 2 Sorted Arrays
        if (pivot == 0)
        {
            st = l;
            en = h;
        }
        else if (key >= A[l] && key <= A[pivot - 1])
        {
            st = l;
            en = pivot - 1;
        }
        else if (key >= A[pivot] && key <= A[h])
        {
            st = pivot;
            en = h;
        }
        else
        {
            return -1;
        }

        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (A[mid] == key)
            {
                return mid;
            }
            else if (A[mid] > key)
            {
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return -1;
    }
};