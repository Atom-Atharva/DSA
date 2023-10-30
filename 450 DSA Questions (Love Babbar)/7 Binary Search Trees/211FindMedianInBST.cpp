// https://practice.geeksforgeeks.org/problems/median-of-bst/1

#include <iostream>
using namespace std;
#include <vector>

// Structure of the binary Search Tree is as
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> inOrderTraversal(Node *root)
{
    // Base Case--
    if (root == NULL)
    {
        return {};
    }

    // Recursive Calls--
    vector<int> leftChildren = inOrderTraversal(root->left);
    vector<int> rightChildren = inOrderTraversal(root->right);

    // Concat Vectors--
    vector<int> ans;
    ans.insert(ans.end(), leftChildren.begin(), leftChildren.end());
    ans.push_back(root->data);
    ans.insert(ans.end(), rightChildren.begin(), rightChildren.end());

    return ans;
}

// your task is to complete the Function
// Function should return median of the BST
float findMedian(struct Node *root)
{
    vector<int> tree = inOrderTraversal(root);

    int n = tree.size();
    float median = (n % 2 == 0) ? ((float)tree[n / 2] + tree[(n / 2) - 1]) / 2 : tree[n / 2];

    return median;
}
