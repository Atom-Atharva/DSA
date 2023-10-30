// https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1

#include <iostream>
using namespace std;
#include <vector>

// Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Approach:
//      Step 1 - Traverse on first tree.
//      Step 2 - Find Element on second tree.
class Solution
{
    bool searchX(Node *root, int x)
    {
        // Base Case--
        if (root == NULL)
        {
            return false;
        }

        // Recursive Calls--
        if (root->data == x)
        {
            return true;
        }
        else if (root->data > x)
        {
            return searchX(root->left, x);
        }
        else
        {
            return searchX(root->right, x);
        }
    }

public:
    int countPairs(Node *root1, Node *root2, int x)
    {
        // Base Case--
        if (root1 == NULL)
        {
            return 0;
        }

        // Recursive Calls--
        int leftChild = countPairs(root1->left, root2, x);
        bool present = searchX(root2, x - root1->data);
        int rightChild = countPairs(root1->right, root2, x);

        return leftChild + rightChild + ((present) ? 1 : 0);
    }
};

// Time Limit Exceeded.
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
    int countPairs(Node *root1, Node *root2, int x)

    {
        vector<int> arr1 = inOrderTraversal(root1);
        vector<int> arr2 = inOrderTraversal(root2);

        int count = 0;
        int st = 0, en = arr2.size() - 1;
        while (st < arr1.size() && en >= 0)
        {
            if (arr1[st] + arr2[en] == x)
            {
                count++;
                st++;
                en--;
            }
            else if (arr1[st] + arr2[en] < x)
            {
                st++;
            }
            else
            {
                en--;
            }
        }

        return count;
    }
};