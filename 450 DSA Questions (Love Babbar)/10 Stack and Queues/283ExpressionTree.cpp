// https://practice.geeksforgeeks.org/problems/expression-tree/1

// Given a full binary expression tree consisting of basic binary operators (+, -,*, /) and some integers, Your task is to evaluate the expression tree.

#include <iostream>
using namespace std;

struct node
{
    string data;
    node *left;
    node *right;
};

class Solution
{
    // Convert into Integer--
    int sti(string data)
    {
        int ans = 0;
        for (int i = 0; i < data.length(); i++)
        {
            ans = ans * 10 + (data[i] - '0');
        }

        return ans;
    }

public:
    /*You are required to complete below method */
    int evalTree(node *root)
    {
        // Base Case--
        if (root == NULL)
        {
            return 0;
        }
        if (root->data >= "0" && root->data <= "9")
        {
            int data = sti(root->data);
            return data;
        }

        // Recursive Calls--
        int lTree = evalTree(root->left);
        int rTree = evalTree(root->right);

        if (root->data == "+")
        {
            return lTree + rTree;
        }
        if (root->data == "-")
        {
            return lTree - rTree;
        }
        if (root->data == "*")
        {
            return lTree * rTree;
        }
        if (root->data == "/")
        {
            return lTree / rTree;
        }
    }
};