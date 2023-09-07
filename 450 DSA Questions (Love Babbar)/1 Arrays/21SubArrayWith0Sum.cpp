// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, bool> umap;
        umap[arr[0]] = 1;
        umap[0] = 1;
        for (int i = 1; i < n; i++)
        {
            arr[i] += arr[i - 1];
            if (umap.count(arr[i]) > 0)
            {
                return true;
            }
            umap[arr[i]] = 1;
        }

            return false;
        }
};