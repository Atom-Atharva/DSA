// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }

        return adj;
    }
};