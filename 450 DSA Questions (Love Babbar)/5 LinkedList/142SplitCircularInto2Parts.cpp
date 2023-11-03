// https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

#include <iostream>
using namespace std;

//  The structure of linked list is the following
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

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *temp = head;

    int size = 1;
    while (temp->next != head)
    {
        temp = temp->next;
        size++;
    }
    Node *save = temp;

    temp = head;
    *head1_ref = temp;

    int mid = (size - 1) / 2;
    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }

    *head2_ref = (temp->next);
    save->next = temp->next;
    temp->next = head;

    return;
}