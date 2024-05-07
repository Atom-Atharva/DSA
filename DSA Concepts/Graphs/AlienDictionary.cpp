// https://www.geeksforgeeks.org/problems/alien-dictionary/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Intuition: Make DG --> Topological Sort
class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        // Make Directed Graph
        vector<int> adj[K];
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < min(dict[i].size(), dict[i - 1].size()); j++)
            {
                if (dict[i][j] != dict[i - 1][j])
                {
                    adj[dict[i - 1][j] - 'a'].push_back(dict[i][j] - 'a');
                    break;
                }
            }
        }

        // Topological Sort
        vector<int> inDegree(K, 0);
        for (int i = 0; i < K; i++)
        {
            for (auto itr : adj[i])
            {
                inDegree[itr]++;
            }
        }

        queue<int> nodes;
        for (int i = 0; i < K; i++)
        {
            if (inDegree[i] == 0)
            {
                nodes.push(i);
            }
        }

        string order = "";
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();

            order += ('a' + node);
            for (auto itr : adj[node])
            {
                inDegree[itr]--;
                if (inDegree[itr] == 0)
                {
                    nodes.push(itr);
                }
            }
        }

        return order;
    }
};