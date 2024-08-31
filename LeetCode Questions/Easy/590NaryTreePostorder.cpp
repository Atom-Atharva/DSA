// https://leetcode.com/problems/n-ary-tree-postorder-traversal/?envType=daily-question&envId=2024-08-26

#include <iostream>
using namespace std;
#include <vector>

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {};
        }

        vector<int> tree;
        for (int i = 0; i < root->children.size(); i++)
        {
            vector<int> child = postorder(root->children[i]);
            tree.insert(tree.end(), child.begin(), child.end());
        }

        tree.push_back(root->val);

        return tree;
    }
};