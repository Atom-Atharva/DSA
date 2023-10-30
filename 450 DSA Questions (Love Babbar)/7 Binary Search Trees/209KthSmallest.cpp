// https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

#include <iostream>
using namespace std;
#include <vector>

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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
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

public:
    int KthSmallestElement(Node *root, int K)
    {
        vector<int> ans = inOrderTraversal(root);

        return (K > ans.size()) ? -1 : ans[K - 1];
    }
};