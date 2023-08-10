// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution
{
    // Calculate Combinations--
    long long nC2(int n)
    {
        return ((long long)n * (n - 1)) / 2;
    }

public:
    // Function to count sub arrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n)
    {
        // Construct Frequency Hash Map for the prefix Sum--
        unordered_map<long long, int> freq;

        // Calculate Prefix sum of the array--
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            freq[sum]++;
        }

        long long count = 0;
        for (auto itr : freq)
        {
            // Handling 0 Cases--
            if (itr.first == 0)
            {
                count += itr.second;
            }

            // Combinations of Frequency--
            count += nC2(itr.second);
        }

        return count;
    }
};