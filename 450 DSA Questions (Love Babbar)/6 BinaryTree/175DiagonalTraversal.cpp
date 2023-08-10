// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// Given a Binary Tree, print the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtrees then left subtree diagonal element should be taken first and then right subtree.

// *************************** Good Concept ***************************************//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//  A binary tree node
struct Node
{
    int data;
    Node *left, *right;
};

vector<int> diagonal(Node *root)
{
    // Base Case--
    if (root == NULL)
    {
        return {};
    }

    // Ans Array and Queue
    vector<int> ans;
    queue<Node *> diag;

    // Push First Root Node--
    diag.push(root);
    while (!diag.empty())
    {
        Node *curr = diag.front();
        diag.pop();

        // Travel to all right nodes on same diagonal--
        while (curr != NULL)
        {
            // Push into array--
            ans.push_back(curr->data);

            // Push into queue--
            if (curr->left != NULL)
            {
                diag.push(curr->left);
            }

            // Travel to next right node on same diagonal--
            curr = curr->right;
        }
    }

    return ans;
}