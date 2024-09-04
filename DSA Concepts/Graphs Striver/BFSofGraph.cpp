// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> graph;
        vector<int> visited(V, 0);

        queue<int> queue;
        queue.push(0);
        visited[0] = 1;

        while (!queue.empty())
        {
            int node = queue.front();
            queue.pop();
            graph.push_back(node);

            for (int i = 0; i < adj[node].size(); i++)
            {
                if (!visited[adj[node][i]])
                {
                    visited[adj[node][i]] = 1;
                    queue.push(adj[node][i]);
                }
            }
        }

        return graph;
    }
};
