// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

#include <iostream>
using namespace std;
#include <queue>

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Structure of the condition
// for sorting the node by its
// data elements
struct myComp
{
    constexpr bool operator()(
        Node *a,
        Node *b)
        const noexcept
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    // Function to merge K sorted linked list.
    Node *mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node *, vector<Node *>, myComp> queue;
        for (int i = 0; i < K; i++)
        {
            Node *head = arr[i];
            while (head != NULL)
            {
                queue.push(head);
                head = head->next;
            }
        }

        Node *head = queue.top();
        Node *temp = head;
        queue.pop();

        while (!queue.empty())
        {
            temp->next = queue.top();
            queue.pop();
            temp = temp->next;
        }

        return head;
    }
};