// https://www.naukri.com/code360/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM

#include <iostream>
using namespace std;
#include <vector>

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

vector<int> getInorder(TreeNode *root)
{
    // Base Case
    if (root == NULL)
    {
        return {};
    }

    vector<int> left = getInorder(root->left);
    left.push_back(root->data);
    vector<int> right = getInorder(root->right);
    left.insert(left.end(), right.begin(), right.end());

    return left;
}

vector<int> getPreorder(TreeNode *root)
{
    // Base Case
    if (root == NULL)
    {
        return {};
    }

    vector<int> tree;
    tree.push_back(root->data);
    vector<int> left = getPreorder(root->left);
    tree.insert(tree.end(), left.begin(), left.end());
    vector<int> right = getPreorder(root->right);
    tree.insert(tree.end(), right.begin(), right.end());

    return tree;
}

vector<int> getPostorder(TreeNode *root)
{
    // Base Case
    if (root == NULL)
    {
        return {};
    }

    vector<int> left = getPostorder(root->left);
    vector<int> right = getPostorder(root->right);
    left.insert(left.end(), right.begin(), right.end());
    left.push_back(root->data);

    return left;
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<int> inOrder = getInorder(root);
    vector<int> preOrder = getPreorder(root);
    vector<int> postOrder = getPostorder(root);

    return {inOrder, preOrder, postOrder};
}