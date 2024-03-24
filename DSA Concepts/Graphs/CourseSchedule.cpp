// https://www.geeksforgeeks.org/problems/course-schedule/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites)
    {
        // Adjacent Matrix
        vector<int> adj[N];
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        // Cycle Detection
        // Form InDegree Array
        vector<int> inDegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (auto itr : adj[i])
            {
                inDegree[itr]++;
            }
        }

        queue<int> nodes;
        for (int i = 0; i < N; i++)
        {
            if (inDegree[i] == 0)
            {
                nodes.push(i);
            }
        }

        vector<int> order;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            order.push_back(node);

            for (auto itr : adj[node])
            {
                inDegree[itr]--;
                if (inDegree[itr] == 0)
                {
                    nodes.push(itr);
                }
            }
        }

        if (order.size() != N)
        {
            return {};
        }
        return order;
    }
};