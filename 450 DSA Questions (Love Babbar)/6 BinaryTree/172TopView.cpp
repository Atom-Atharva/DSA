// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the extreme ones only(i.e. leftmost and rightmost).
// For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
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

            // Insert into map--
            if (dist.count(pos) == 0)
            {
                dist[pos] = temp;
            }

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