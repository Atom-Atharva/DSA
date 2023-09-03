// https://leetcode.com/problems/sliding-window-maximum/

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window

//********************************* Good Concept *******************************************//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>

// Method 2: Priority Queue Storing Pair <element,position>
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> maxSliding;
        priority_queue<pair<int, int>> maxQueue;

        // Insert into Priority Queue--
        for (int i = 0; i < k; i++)
        {
            // Store element and position--
            maxQueue.push({nums[i], i});
        }

        maxSliding.push_back(maxQueue.top().first);

        // Insertion over rest of the elements--
        for (int i = k; i < nums.size(); i++)
        {
            // Insert Current Element--
            maxQueue.push({nums[i], i});

            // Check for Valid Elements--
            while (maxQueue.top().second <= i - k)
            {
                maxQueue.pop();
            }

            // Insert into array--
            maxSliding.push_back(maxQueue.top().first);
        }

        return maxSliding;
    }
};

// Method 1: Priority Queue
// Time Limit Exceeded
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         vector<int> maxSliding;
//         priority_queue<int> maxStore;

//         // Make Sliding Window--
//         for (int i = 0; i < k; i++)
//         {
//             maxStore.push(nums[i]);
//         }

//         maxSliding.push_back(maxStore.top());

//         for (int i = k; i < nums.size(); i++)
//         {
//             // Temporary Storage.
//             stack<int> storage;
//             int prev = nums[i - k];

//             // Remove prev element.
//             while (maxStore.top() != prev)
//             {
//                 storage.push(maxStore.top());
//                 maxStore.pop();
//             }

//             maxStore.pop();

//             // Insert again into priority Queue.
//             while (!storage.empty())
//             {
//                 maxStore.push(storage.top());
//                 storage.pop();
//             }

//             // Insert new element--
//             maxStore.push(nums[i]);

//             // Update answer--
//             maxSliding.push_back(maxStore.top());
//         }

//         return maxSliding;
//     }
// };