// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

#include <iostream>
using namespace std;
#include <unordered_map>

// Method 1: Iterate Over each Element
// Time Complexity: O(n^2)

// Method 2: HasMap
// Time Complexity: O(n)
class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // Insert into Map.
        unordered_map<int, int> freq;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += freq[k - arr[i]];
            freq[arr[i]]++;
        }

        return ans;
    }
};