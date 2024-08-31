#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        // Create an adjacency list
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            adj[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        // Priority queue to maximize probability
        priority_queue<pair<double, int>> pq;
        vector<double> prob(n, 0.0);
        prob[start] = 1.0;
        pq.push({1.0, start});

        while (!pq.empty())
        {
            // Get the current node and probability
            auto curr = pq.top(); // curr is a pair
            pq.pop();
            double currProb = curr.first;
            int node = curr.second;

            if (node == end)
            {
                return currProb;
            }

            // Loop through all neighbors of the current node
            for (int i = 0; i < adj[node].size(); i++)
            {
                int neighbor = adj[node][i].first;
                double edgeProb = adj[node][i].second;

                double newProb = currProb * edgeProb;
                if (newProb > prob[neighbor])
                {
                    prob[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        return 0.0; // No path found
    }
};
