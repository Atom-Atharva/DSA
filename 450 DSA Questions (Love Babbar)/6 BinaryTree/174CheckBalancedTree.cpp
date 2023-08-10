// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

// Given a binary tree, find if it is height balanced or not.
// A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree.

// A height balanced tree
//         1
//      /     \
//    10      39
//   /
// 5

// An unbalanced tree
//         1
//      /
//    10
//   /
// 5

#include <iostream>
using namespace std;
#include <vector>

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
    int height(Node *root)
    {
        // Base Case--
        if (root == NULL)
        {
            return 0;
        }

        // Recursive Call--
        int lHeight = height(root->left);
        int rHeight = height(root->right);

        return 1 + max(lHeight, rHeight);
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        int lHeight = height(root->left);
        int rHeight = height(root->right);

        if (abs(lHeight - rHeight) > 1)
        {
            return false;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        return left && right;
    }
};