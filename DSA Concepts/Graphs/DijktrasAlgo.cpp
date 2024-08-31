#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <climits>

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // HOLDS MIN DISTANCES FROM SOURCE
        vector<int> distances(V, INT_MAX);
        distances[S] = 0;

        // BFS ON MIN DISTANCE NODE
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
        queue.push({0, S});

        // While All Optimal Nodes Visited
        while (!queue.empty())
        {
            // Min Distance Node
            int node = queue.top().second;
            int currDistance = queue.top().first;
            queue.pop();

            // For Each Adjacent Node
            for (auto itr : adj[node])
            {
                // If Distance is MINIMUM push it INTO QUEUE
                if ((long long)currDistance + itr[1] < distances[itr[0]])
                {
                    distances[itr[0]] = currDistance + itr[1];
                    queue.push({distances[itr[0]], itr[0]});
                }
            }
        }

        return distances;
    }
};
