// https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

#include <iostream>
using namespace std;
#include <stack>

//  structure for a node
struct Node
{
    int data;
    struct Node *next;
};

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{
    struct Node *prev = *head, *curr = prev->next;

    while (curr != *head)
    {
        if (curr->data == key)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
        curr = curr->next;
        prev = prev->next;
    }
    if(curr->data==key){
        prev->next=curr->next;
        *head=curr->next;
        delete curr;
    }

    return;
}   

/* Function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    struct Node *curr = *head_ref;
    stack<Node *> nodes;

    while (curr->next != *head_ref)
    {
        nodes.push(curr);
        curr = curr->next;
    }
    nodes.push(curr);

    *head_ref = nodes.top();
    Node *prev = nodes.top();
    nodes.pop();

    while (!nodes.empty())
    {
        Node *top = nodes.top();
        nodes.pop();

        prev->next = top;
        prev = top;
    }
    prev->next = *head_ref;

    return;
}