// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *last = NULL;

Node *reverseDLL(Node *head)
{
    // Base Case--
    if (head == NULL || head->next == NULL)
    {
        head->prev = NULL;
        last = head;
        return head;
    }

    // Recursive Call--
    Node *rev = reverseDLL(head->next);

    last->next = head;
    head->prev = last;
    head->next = NULL;
    last = head;

    return rev;
}