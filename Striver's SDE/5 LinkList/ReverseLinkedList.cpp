// https://leetcode.com/problems/reverse-linked-list/description/

#include <iostream>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative Approach
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *prev = head;
        ListNode *curr = head->next;

        ListNode *temp = curr->next;

        prev->next = NULL;
        curr->next = prev;

        prev = curr;
        curr = temp;

        while (curr)
        {
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

// Recursive Approach
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Recursive Call
        ListNode *reversed = reverseList(head->next);

        // Iterate to Last Element
        ListNode *temp = reversed;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Insert head to Last
        temp->next = head;
        head->next = NULL;

        // Return Reversed new head
        return reversed;
    }
};