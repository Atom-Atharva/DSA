// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        // Base Case
        if (root == NULL)
        {
            return NULL;
        }

        // Level Order
        queue<pair<Node *, int>> queue;
        queue.push({root, 0});

        int prev = -1;
        Node *prevNode = NULL;
        while (!queue.empty())
        {
            Node *curr = queue.front().first;
            int lvl = queue.front().second;
            queue.pop();

            if (prev != lvl)
            {
                prev = lvl;
            }
            else
            {
                prevNode->next = curr;
            }
            prevNode = curr;

            if (curr->left)
            {
                queue.push({curr->left, lvl + 1});
            }
            if (curr->right)
            {
                queue.push({curr->right, lvl + 1});
            }
        }

        return root;
    }
};