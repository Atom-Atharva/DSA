// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

//                       20
//                     /    \
//                   8       22
//                 /   \        \
//               5      3       25
//                     /   \      
//                   10    14

// For the above tree, the bottom view is 5 10 3 14 25.
// If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

//                       20
//                     /    \
//                   8       22
//                 /   \     /   \
//               5      3 4     25
//                      /    \      
//                  10       14

// For the above tree the output should be 5 10 4 14 25.

// Note: The Input/Output format and Example given are used for the system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from the stdin/console. The task is to complete the function specified, and not to write the full code.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {

        if (root == NULL)
        {
            return {};
        }

        // Level Order Traversal on Tree--
        queue<pair<Node *, int>> tree;
        tree.push({root, 0});

        // Un-Order Map to store distance from center--
        unordered_map<int, Node *> dist;

        // Level Order Traversal--
        while (!tree.empty())
        {
            // Remove from Queue--
            Node *temp = tree.front().first;
            int pos = tree.front().second;
            tree.pop();

            // Insert into map and Update to Latest Value--
            dist[pos] = temp;

            // Insert into Queue--
            if (temp->left != NULL)
            {
                tree.push({temp->left, pos - 1});
            }
            if (temp->right != NULL)
            {
                tree.push({temp->right, pos + 1});
            }
        }

        // Insert into array--
        vector<pair<int, int>> pairAns;
        for (auto itr : dist)
        {
            pair<int, int> temp = {itr.first, itr.second->data};
            pairAns.push_back(temp);
        }

        // Sort PairArray--
        sort(pairAns.begin(), pairAns.end());

        // Insert into Array--
        vector<int> ans;
        for (int i = 0; i < pairAns.size(); i++)
        {
            ans.push_back(pairAns[i].second);
        }

        return ans;
    }
};
