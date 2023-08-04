// https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

// Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with its own memory the original lists should not be changed.
// Note: The linked list elements are not necessarily distinct.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *findIntersection(Node *head1, Node *head2)
{
    Node *newHead = NULL;
    Node *newTail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            if (newHead != NULL)
            {
                newTail->next = head1;
                newTail = newTail->next;
            }
            else
            {
                newHead = head1;
                newTail = head1;
            }

            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else
        {
            head1 = head1->next;
        }
    }
    newTail->next = NULL;
    return newHead;
}