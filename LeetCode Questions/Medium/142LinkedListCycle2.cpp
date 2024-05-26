// https://leetcode.com/problems/linked-list-cycle-ii/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        bool cycle = false;
        while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cycle = true;
                break;
            }
        }
        if (!cycle)
        {
            return NULL;
        }

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};