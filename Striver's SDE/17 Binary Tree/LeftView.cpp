// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// A binary tree node
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

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return {};
    }

    // Get Level Wise Order and Take first Node.
    vector<int> view;
    queue<pair<Node *, int>> levelWise;
    levelWise.push({root, 1});

    int prevLvl = 0;
    while (!levelWise.empty())
    {
        Node *curr = levelWise.front().first;
        int lvl = levelWise.front().second;
        levelWise.pop();

        if (lvl != prevLvl)
        {
            view.push_back(curr->data);
        }
        prevLvl = lvl;
        if (curr->left)
        {
            levelWise.push({curr->left, lvl + 1});
        }
        if (curr->right)
        {
            levelWise.push({curr->right, lvl + 1});
        }
    }

    return view;
}