// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <climits>

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // Dijktra's Algorithm + Storing Parent Node (Where it is comming from)
        vector<int> distances(n, INT_MAX);
        vector<int> parent(n, -1);
        distances[0] = 0;
        parent[0] = 0;

        // Adjacentcy List
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Queue to store {distance, node} -- MIN HEAP
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        queue.push({0, 0});

        // BFS
        while (!queue.empty())
        {
            int node = queue.top().second;
            int currDistance = queue.top().first;
            queue.pop();

            for (auto itr : adj[node])
            {
                if (currDistance + itr.second < distances[itr.first])
                {
                    distances[itr.first] = currDistance + itr.second;
                    parent[itr.first] = node;
                    queue.push({distances[itr.first], itr.first});
                }
            }
        }

        // GOT ALL DISTANCES AND CORRESPONDING PARENTS
        if (distances[n - 1] == INT_MAX)
        {
            return {-1};
        }

        vector<int> ans;
        // WEIGHT ON FIRST INDEX
        ans.push_back(distances[n - 1]);

        // GET PATH
        vector<int> path;
        int node = n - 1;
        path.push_back(node + 1);

        while (node != 0)
        {
            node = parent[node];
            path.push_back(node + 1);
        }

        for (int i = path.size() - 1; i >= 0; i--)
        {
            ans.push_back(path[i]);
        }

        return ans;
    }
};