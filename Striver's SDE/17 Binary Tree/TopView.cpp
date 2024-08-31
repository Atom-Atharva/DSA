// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <map>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {};
        }

        // Level Order Traversal
        queue<pair<Node *, int>> queue;
        queue.push({root, 0});

        // Distance From Center
        map<int, Node *> umap;

        while (!queue.empty())
        {
            Node *curr = queue.front().first;
            int dist = queue.front().second;
            queue.pop();

            if (umap.count(dist) == 0)
            {
                umap[dist] = curr;
            }

            if (curr->left)
            {
                queue.push({curr->left, dist - 1});
            }
            if (curr->right)
            {
                queue.push({curr->right, dist + 1});
            }
        }

        // Get Bottom View
        vector<int> view;
        for (auto itr : umap)
        {
            view.push_back(itr.second->data);
        }

        return view;
    }
};