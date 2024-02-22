// https://leetcode.com/problems/add-two-numbers/

#include <iostream>
using namespace std;

//   Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Base Case--
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        else if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }

        ListNode *head = NULL;
        ListNode *curr = NULL;

        int carry = 0;
        while (l1 && l2)
        {
            int val = l1->val + l2->val + carry;
            carry = val / 10;
            val %= 10;

            ListNode *sum = new ListNode(val);

            if (head == NULL)
            {
                head = sum;
                curr = sum;
            }
            else
            {
                curr->next = sum;
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int val = l1->val + carry;
            carry = val / 10;
            val %= 10;

            ListNode *sum = new ListNode(val);

            if (head == NULL)
            {
                head = sum;
                curr = sum;
            }
            else
            {
                curr->next = sum;
                curr = curr->next;
            }

            l1 = l1->next;
        }
        while (l2)
        {
            int val = l2->val + carry;
            carry = val / 10;
            val %= 10;

            ListNode *sum = new ListNode(val);

            if (head == NULL)
            {
                head = sum;
                curr = sum;
            }
            else
            {
                curr->next = sum;
                curr = curr->next;
            }

            l2 = l2->next;
        }

        if (carry)
        {
            ListNode *sum = new ListNode(carry);
            curr->next = sum;
            curr = curr->next;
        }

        return head;
    }
};