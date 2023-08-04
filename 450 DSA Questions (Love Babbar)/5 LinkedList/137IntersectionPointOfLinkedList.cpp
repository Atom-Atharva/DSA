// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

// Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

#include <iostream>
using namespace std;
#include <unordered_map>

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

// Method 2: Absolute Difference--
int intersectPoint(Node *head1, Node *head2)
{
    int n1 = 0;
    Node *tail1 = head1;

    while (tail1 != NULL)
    {
        n1++;
        tail1 = tail1->next;
    }

    int n2 = 0;
    Node *tail2 = head2;

    while (tail2 != NULL)
    {
        n2++;
        tail2 = tail2->next;
    }

    int move = abs(n1 - n2);
    tail1 = head1;
    tail2 = head2;
    if (n1 > n2)
    {
        while (move--)
        {
            tail1 = tail1->next;
        }
    }
    if (n2 > n1)
    {
        while (move--)
        {
            tail2 = tail2->next;
        }
    }

    while (tail1 != NULL && tail2 != NULL && tail1 != tail2)
    {
        tail1 = tail1->next;
        tail2 = tail2->next;
    }

    return (tail1 == NULL || tail2 == NULL) ? -1 : tail1->data;
}

// Method 1: TIME LIMIT EXCEEDED
// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    // Base Case--
    if (head1 == NULL || head2 == NULL)
    {
        return -1;
    }

    unordered_map<Node *, bool> nodes;
    while (head1 != NULL)
    {
        nodes[head1] = 1;
        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        if (nodes.count(head2) > 0)
        {
            return head2->data;
        }
        head2 = head2->next;
    }
    return -1;
}