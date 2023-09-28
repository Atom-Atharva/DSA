// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

// Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

#include <iostream>
using namespace std;
#include <algorithm>

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        sort(arr, arr + N);

        int maxLongest = 1;
        int longest = 1;
        for (int i = 1; i < N; i++)
        {
            // Handle Duplicates--
            if (arr[i - 1] == arr[i])
                continue;

            // Check consecutives--
            if (arr[i - 1] + 1 == arr[i])
                longest++;

            else
                longest = 1;

            maxLongest = max(maxLongest, longest);
        }

        return maxLongest;
    }
};