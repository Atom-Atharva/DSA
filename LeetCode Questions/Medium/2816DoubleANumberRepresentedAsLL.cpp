// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
using namespace std;

// Method--
// 1. Reverse LL
// 2. Multiply by 2
// 3. Reverse LL

class Solution
{
    ListNode *reverseLL(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *tail = head->next;
        ListNode *newHead = reverseLL(head->next);

        tail->next = head;
        head->next = NULL;
        return newHead;
    }

public:
    ListNode *doubleIt(ListNode *head)
    {
        head = reverseLL(head);

        int carry = 0;
        ListNode *temp = head;
        ListNode *tail = temp;
        while (temp != NULL)
        {
            tail = temp;

            int res = (2 * temp->val + carry);
            temp->val = res % 10;
            carry = res / 10;

            temp = temp->next;
        }

        if (carry)
        {
            ListNode *node = new ListNode(carry);
            tail->next = node;
        }

        head = reverseLL(head);

        return head;
    }
};