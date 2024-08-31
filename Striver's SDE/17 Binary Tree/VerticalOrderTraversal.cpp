// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Point
{
    TreeNode *node;
    int x;
    int y;

    Point(TreeNode *node, int x, int y)
    {
        this->node = node;
        this->x = x;
        this->y = y;
    }
};

class Comparator
{
public:
    bool operator()(Point *a, Point *b)
    {
        if (a->x == b->x)
        {
            return a->node->val > b->node->val;
        }

        return a->x > b->x;
    }
};

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<Point *> queue;
        queue.push(new Point(root, 0, 0));

        // map to store dist(y) to points on that distance
        unordered_map<int, priority_queue<Point *, vector<Point *>, Comparator>> umap;

        int minIndex = 0;
        int maxIndex = 0;
        while (!queue.empty())
        {
            // Get Front
            TreeNode *curr = queue.front()->node;
            int x = queue.front()->x;
            int y = queue.front()->y;

            // Insert into PQ
            umap[y].push(queue.front());

            // Figure out range
            minIndex = min(minIndex, y);
            maxIndex = max(maxIndex, y);

            queue.pop();
            // Update Queue
            if (curr->left)
            {
                queue.push(new Point(curr->left, x + 1, y - 1));
            }
            if (curr->right)
            {
                queue.push(new Point(curr->right, x + 1, y + 1));
            }
        }

        vector<vector<int>> tree;
        for (int i = minIndex; i <= maxIndex; i++)
        {
            vector<int> vertical;
            while (!umap[i].empty())
            {
                vertical.push_back(umap[i].top()->node->val);
                umap[i].pop();
            }
            tree.push_back(vertical);
        }

        return tree;
    }
};