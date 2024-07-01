// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/?envType=daily-question&envId=2024-06-29

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    vector<int> dfs(int node, vector<vector<int>> &matrix, vector<vector<int>> &childrens, vector<bool> &visited)
    {
        // If Already Visited
        if (visited[node])
        {
            vector<int> child = childrens[node];
            child.push_back(node);

            return child;
        }

        // Mark Visited
        visited[node] = true;

        vector<int> childs = {};
        for (int i = 0; i < matrix.size(); i++)
        {

            if (matrix[node][i] == 1)
            {
                vector<int> subchild = dfs(i, matrix, childrens, visited);
                childs.insert(childs.end(), subchild.begin(), subchild.end());
            }
        }
        if (childs.size() == 0)
        {
            childrens[node] = {};
            return {node};
        }

        // Store in Childrens in ascending order;
        sort(childs.begin(), childs.end());
        vector<int> uniques;
        uniques.push_back(childs[0]);
        for (int i = 1; i < childs.size(); i++)
        {
            if (childs[i] != uniques[uniques.size() - 1])
            {
                uniques.push_back(childs[i]);
            }
        }
        childrens[node] = uniques;

        // Curr Node to its Parent
        uniques.push_back(node);
        return uniques;
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        // Reverse Graph
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < edges.size(); i++)
        {
            matrix[edges[i][1]][edges[i][0]] = 1;
        }

        // Return Child Component of every Node
        vector<vector<int>> childrens(n);
        vector<bool> visited(n, false);

        // Over All Nodes
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, matrix, childrens, visited);
            }
        }

        return childrens;
    }
};