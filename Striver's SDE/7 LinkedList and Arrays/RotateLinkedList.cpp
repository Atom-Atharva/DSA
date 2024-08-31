// https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // MAKE LIST CIRCULAR
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;

        // DISJOINT AT Kth NODE
        temp = head;
        while (k != 1)
        {
            temp = temp->next;
            k--;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
