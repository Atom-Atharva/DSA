// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

// Input:
//         1
//       /   \
//      2     3
//     / \   /  \
//    4   5 6    7
// Output:
// 1 3 2 4 5 6 7

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

// Structure of the node of the binary tree is as
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
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        // Base Case--
        if (root == NULL)
        {
            return {};
        }

        stack<Node *> ltr; // Left to Right
        stack<Node *> rtl; // Right to Left

        rtl.push(root);
        bool flag = false;

        vector<int> ans;

        while (!rtl.empty() || !ltr.empty())
        {
            // Push Left To Right--
            if (flag)
            {
                Node *curr = ltr.top();
                ltr.pop();

                if (curr->right != NULL)
                {
                    rtl.push(curr->right);
                }
                if (curr->left != NULL)
                {
                    rtl.push(curr->left);
                }

                ans.push_back(curr->data);
                if (ltr.empty())
                {
                    flag = false;
                }
            }
            // Push Right to Left--
            else
            {
                Node *curr = rtl.top();
                rtl.pop();

                if (curr->left != NULL)
                {
                    ltr.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    ltr.push(curr->right);
                }

                ans.push_back(curr->data);
                if (rtl.empty())
                {
                    flag = true;
                }
            }
        }
        return ans;
    }
};