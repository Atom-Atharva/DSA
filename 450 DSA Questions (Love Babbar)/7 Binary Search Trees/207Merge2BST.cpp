// https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    // Method 1:
    // Step 1- Perform InOrder Traversal on both the trees.
    // Step 2- Merge 2 Sorted Arrays
    vector<int> merge(Node *root1, Node *root2)
    {
        // InOrder Traversal
        vector<int> array1 = inOrderTraversal(root1);
        vector<int> array2 = inOrderTraversal(root2);

        // Merge 2 Sorted Arrays
        vector<int> merge;
        int i = 0, j = 0;
        while (i < array1.size() && j < array2.size())
        {
            if (array1[i] < array2[j])
            {
                merge.push_back(array1[i]);
                i++;
            }
            else
            {
                merge.push_back(array2[j]);
                j++;
            }
        }
        while (i < array1.size())
        {
            merge.push_back(array1[i++]);
        }
        while (j < array2.size())
        {
            merge.push_back(array2[j++]);
        }

        return merge;
    }
};