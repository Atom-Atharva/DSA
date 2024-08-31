// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

class Solution
{
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
    {
        // Sort Both Arrays
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        // Insert Sum,i,j in Heap
        priority_queue<pair<int, pair<int, int>>> queue;
        queue.push({A[0] + B[0], {0, 0}});

        // Check Visited
        set<pair<int, int>> visited;
        visited.insert({0, 0});

        // Take Out from Heap --> and add i+1,j and i,j+1
        vector<int> maxElements;
        while (!queue.empty() && K--)
        {
            int currMax = queue.top().first;
            int i = queue.top().second.first;
            int j = queue.top().second.second;
            queue.pop();

            maxElements.push_back(currMax);

            // Add Other Elements
            if (i + 1 < A.size() && (visited.count({i + 1, j}) == 0))
            {
                visited.insert({i + 1, j});
                queue.push({A[i + 1] + B[j], {i + 1, j}});
            }
            if (j + 1 < B.size() && (visited.count({i, j + 1}) == 0))
            {
                visited.insert({i, j + 1});
                queue.push({A[i] + B[j + 1], {i, j + 1}});
            }
        }

        return maxElements;
    }
};