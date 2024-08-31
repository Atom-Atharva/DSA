// https://www.naukri.com/code360/problems/preorder-traversal_3838888?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include <iostream>
#include <vector>
using namespace std;

// Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// PreOrder : Root, Left, Right
// Special Type of Traversal
// TC : O(N)
// SC : O(1)
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Base Case
    if (root == NULL)
    {
        return {};
    }

    vector<int> tree;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        tree.push_back(curr->data);
        if (curr->left == NULL)
        {
            curr = curr->right;
        }
        else
        {
            TreeNode *temp = curr->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = curr->right;

            temp = curr->left;
            curr->left = NULL;
            curr = temp;
        }
    }

    return tree;
}