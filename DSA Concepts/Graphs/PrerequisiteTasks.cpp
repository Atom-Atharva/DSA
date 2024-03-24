// https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Intuition: Cycle Detection
class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        // Adjacent Matrix
        vector<int> adj[N];
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
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

        int nodesTraverse = 0;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            nodesTraverse++;

            for (auto itr : adj[node])
            {
                inDegree[itr]--;
                if (inDegree[itr] == 0)
                {
                    nodes.push(itr);
                }
            }
        }

        return nodesTraverse != N;
    }
};