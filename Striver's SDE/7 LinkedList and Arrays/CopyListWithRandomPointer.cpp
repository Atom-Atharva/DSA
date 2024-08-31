// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <iostream>
using namespace std;
#include <unordered_map>

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        // Stores Relation of Original Node to Copy Node
        unordered_map<Node *, Node *> umap;

        Node *newHead = new Node(head->val);
        umap[head] = newHead;

        Node *temp = newHead;

        while (head)
        {
            // ADD NODE IF NOT AVAILABLE
            if (head->next != NULL && umap.count(head->next) == 0)
            {
                Node *newNode = new Node(head->next->val);
                umap[head->next] = newNode;
            }
            if (head->random != NULL && umap.count(head->random) == 0)
            {
                Node *newRandom = new Node(head->random->val);
                umap[head->random] = newRandom;
            }

            // CONNECT TO CURR
            if (head->next == NULL)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = umap[head->next];
            }
            if (head->random == NULL)
            {
                temp->random = NULL;
            }
            else
            {
                temp->random = umap[head->random];
            }

            // Iterate to next
            head = head->next;
            temp = temp->next;
        }

        return newHead;
    }
};