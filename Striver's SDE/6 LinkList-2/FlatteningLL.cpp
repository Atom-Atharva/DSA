// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <iostream>
using namespace std;
#include <vector>

// Node structure  used in the program
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    vector<Node *> heads;
    while (root)
    {
        heads.push_back(root);
        Node *temp = root->next;
        root->next = NULL;
        root = temp;
    }

    bool allNull = false;
    Node *head = NULL;
    Node *tail = NULL;
    while (!allNull)
    {
        Node *minNode = NULL;
        int index = -1;
        for (int i = 0; i < heads.size(); i++)
        {
            if (heads[i] != NULL)
            {
                if (minNode == NULL)
                {
                    minNode = heads[i];
                    index = i;
                }
                else
                {
                    if (minNode->data > heads[i]->data)
                    {
                        minNode = heads[i];
                        index = i;
                    }
                }
            }
        }
        if (minNode == NULL)
        {
            allNull = true;
            break;
        }

        // Update Heads
        heads[index] = minNode->bottom;

        // Append minNode to Tail
        if (head == NULL)
        {
            head = minNode;
            tail = minNode;
        }
        else
        {
            tail->bottom = minNode;
            tail = tail->bottom;
        }
        tail->bottom = NULL;
    }

    return head;
}