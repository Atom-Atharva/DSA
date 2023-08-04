// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

// Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
// Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

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
    Node *mergeList(Node *head1, Node *head2)
    {
        // Merge Sorted List--
        Node *tail1 = head1;
        Node *tail2 = head2;

        Node *newHead = NULL;
        Node *newTail = NULL;

        while (tail1 != NULL && tail2 != NULL)
        {
            if (tail1->data < tail2->data)
            {
                if (newHead == NULL)
                {
                    newHead = tail1;
                    newTail = tail1;
                }
                else
                {
                    newTail->next = tail1;
                    newTail = newTail->next;
                }
                tail1 = tail1->next;
            }
            else
            {
                if (newHead == NULL)
                {
                    newHead = tail2;
                    newTail = tail2;
                }
                else
                {
                    newTail->next = tail2;
                    newTail = newTail->next;
                }
                tail2 = tail2->next;
            }
        }
        if (tail1 != NULL)
        {
            newTail->next = tail1;
        }
        if (tail2 != NULL)
        {
            newTail->next = tail2;
        }

        return newHead;
    }

    Node *mid(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // For first mid--
        Node *fast = head->next;
        Node *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Node *sort(Node *head)
    {
        // Base Case--
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Calculate Mid--
        // int mid = n / 2;
        // int pos = 1;

        // Find Mid--
        // Node *tail = head;
        // while (pos < mid)
        // {
        //     pos++;
        //     tail = tail->next;
        // }
        Node *tail = mid(head);
        Node *next = tail->next;
        tail->next = NULL;

        // Call Recursion--
        Node *head1 = sort(head);
        Node *head2 = sort(next);

        // Merge 2 Sorted List--
        Node *newHead = mergeList(head1, head2);

        return newHead;
    }

public:
    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        // Find Length--
        // int n = 0;
        // Node *tail = head;
        // while (tail != NULL)
        // {
        //     tail = tail->next;
        //     n++;
        // }

        Node *newHead = sort(head);
        return newHead;
    }
};