// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        priority_queue<int> queue(a.begin(), a.end());

        for (int i = 0; i < m; i++)
        {
            queue.push(b[i]);
        }

        vector<int> ans;
        while (!queue.empty())
        {
            ans.push_back(queue.top());
            queue.pop();
        }

        return ans;
    }
};