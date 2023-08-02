// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

// Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // Min Heap--
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push into Heap--
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < K; j++)
            {
                pq.push(arr[i][j]);
            }
        }

        // Remove from Heap--
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
