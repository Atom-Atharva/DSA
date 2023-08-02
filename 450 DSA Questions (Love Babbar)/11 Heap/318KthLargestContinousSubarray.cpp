// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

// You are given an array Arr of size N. You have to find the K-th largest sum of contiguous subarray within the array elements.

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        // Min Heap--
        priority_queue<int, vector<int>, greater<int>> queue;

        // Insert Element inside Heap--
        for (int i = 0; i < N; i++)
        {
            int element = 0;
            for (int j = i; j < N; j++)
            {
                element += Arr[j];
                // Maintain fix Size of HEAP--
                if (queue.size() != K)
                {
                    queue.push(element);
                }
                else
                {
                    if (queue.top() < element)
                    {
                        queue.pop();
                        queue.push(element);
                    }
                }
            }
        }

        return queue.top();
    }
};