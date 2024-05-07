// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <climits>

// Approach
//      - Topological Sort
//      - Relaxation of Vertices
class Solution
{
    vector<int> topoSort(int N, vector<pair<int, int>> adj[])
    {
        vector<int> inDegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (auto itr : adj[i])
            {
                inDegree[itr.first]++;
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

        vector<int> topo;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();

            topo.push_back(node);
            for (auto itr : adj[node])
            {
                inDegree[itr.first]--;
                if (inDegree[itr.first] == 0)
                {
                    nodes.push(itr.first);
                }
            }
        }

        return topo;
    }

    vector<int> relaxation(int N, vector<pair<int, int>> adj[], vector<int> &topo)
    {
        vector<int> distances(N, INT_MAX);
        distances[topo[0]] = 0;

        for (int i = 0; i < topo.size(); i++)
        {
            if (distances[topo[i]] == INT_MAX)
            {
                continue;
            }
            for (auto itr : adj[topo[i]])
            {
                int dist = distances[topo[i]] + itr.second;
                distances[itr.first] = min(distances[itr.first], dist);
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (distances[i] == INT_MAX)
            {
                distances[i] = -1;
            }
        }

        return distances;
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // Topological Sort
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<int> topo = topoSort(N, adj);

        // Relaxation of Vertices
        vector<int> distances = relaxation(N, adj, topo);

        return distances;
    }
};