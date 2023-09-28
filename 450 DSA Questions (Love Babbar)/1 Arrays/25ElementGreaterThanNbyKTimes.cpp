// https://practice.geeksforgeeks.org/problems/count-element-occurences/1

// Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            umap[arr[i]]++;
        }

        int count = 0;
        for (auto itr : umap)
        {
            if (itr.second > n / k)
            {
                count++;
            }
        }

        return count;
    }
};