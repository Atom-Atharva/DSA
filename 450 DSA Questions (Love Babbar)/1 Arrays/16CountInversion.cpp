// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// Given an array of integers. Find the Inversion Count in the array.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

#include <iostream>
using namespace std;

// Method 1: Check each Element
// Time Complexity: O(n^2)

// Method 2: Merge Sort
// Time Complexity: O(nlogn)
class Solution
{
    // Merge 2 Sorted Arrays--
    void merge(long long arr[], long long st, long long mid, long long en, long long &ans)
    {
        long long i = st, j = mid + 1;

        long long merge[en - st + 1];
        int k = 0;
        while (i <= mid && j <= en)
        {
            if (arr[i] > arr[j])
            {
                // Update Inversion Count--
                ans += mid - i + 1;
                merge[k++] = arr[j];
                j++;
            }
            else
            {
                merge[k++] = arr[i];
                i++;
            }
        }

        // Handle Remaining Elements--
        while (i <= mid)
        {
            merge[k++] = arr[i++];
        }
        while (j <= en)
        {
            merge[k++] = arr[j++];
        }

        for (long long i = 0; i < en - st + 1; i++)
        {
            arr[i + st] = merge[i];
        }

        return;
    }

    void mergeSort(long long arr[], long long st, long long en, long long &ans)
    {
        // Base Case--
        if (st >= en)
        {
            return;
        }

        // Recursive Call--
        long long mid = (st + en) / 2;
        mergeSort(arr, st, mid, ans);
        mergeSort(arr, mid + 1, en, ans);

        // Merge 2 Sorted Arrays--
        merge(arr, st, mid, en, ans);

        return;
    }

public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long ans = 0;
        mergeSort(arr, 0, N - 1, ans);

        return ans;
    }
};