// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

// Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

#include <iostream>
using namespace std;
#include <algorithm>

class Solution
{
    long long countDoubles(long long arr[], int n, long long sum, int st, int en)
    {
        long long int count = 0;

        // Find First Valid Answer--
        while (st < en)
        {
            if ((long long)arr[st] + arr[en] < sum)
            {
                count += en - st;
                st++;
            }
            else
            {
                en--;
            }
        }

        return count;
    }

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        long long ans = 0;

        // Sort the Array--
        sort(arr, arr + n);

        // Fix One Number--
        for (int i = 0; i < n - 2; i++)
        {
            // Take 2 Numbers--
            ans += countDoubles(arr, n, sum - arr[i], i + 1, n - 1);
        }

        return ans;
    }
};