// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int &n)
    {
        // Base Case--
        if (head == NULL)
        {
            return NULL;
        }

        // Recursive Call--
        ListNode *next = removeNthFromEnd(head->next, n);
        n--;

        // Delete Current Node--
        if (n == 0)
        {
            ListNode *next = head->next;
            delete head;
            return next;
        }

        head->next = next;
        return head;
    }
};