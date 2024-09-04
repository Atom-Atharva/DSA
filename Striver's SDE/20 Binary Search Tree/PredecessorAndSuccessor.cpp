// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

#include <iostream>
using namespace std;

// BST Node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{

    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key, Node *&prev)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }

        findPreSuc(root->left, pre, suc, key, prev);
        // Set pre and suc
        if (root->key >= key && prev && prev->key < key)
        {
            pre = prev;
        }
        if (root->key > key && suc == NULL)
        {
            suc = root;
        }
        findPreSuc(root->right, pre, suc, key, root);

        return;
    }

public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        if (root == NULL)
        {
            return;
        }

        // Store Prev and InOrder
        Node *prev = NULL;
        findPreSuc(root, pre, suc, key, prev);
        if (pre == NULL)
        {
            pre = prev;
        }

        return;
    }
};