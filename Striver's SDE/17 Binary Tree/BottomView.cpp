// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <map>

// A binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Method : Latter Distance from the center.
class Solution
{
public:
    vector<int> bottomView(Node *root)
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

            umap[dist] = curr;

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