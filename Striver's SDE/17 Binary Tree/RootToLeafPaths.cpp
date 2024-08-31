// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

#include <iostream>
using namespace std;
#include <vector>

// Definition for Binary Tree Node
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

class Solution
{
    void getPaths(Node *root, vector<int> &path, vector<vector<int>> &rootToLeaf)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }
        path.push_back(root->data);
        if (root->left == NULL && root->right == NULL)
        {
            rootToLeaf.push_back(path);
            path.pop_back();
            return;
        }

        getPaths(root->left, path, rootToLeaf);
        getPaths(root->right, path, rootToLeaf);

        path.pop_back();

        return;
    }

public:
    vector<vector<int>> Paths(Node *root)
    {
        vector<int> path;
        vector<vector<int>> rootToLeaf;
        getPaths(root, path, rootToLeaf);

        return rootToLeaf;
    }
};