// https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23

// Definition for singly-linked list.
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

class Solution
{
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            ListNode *curr = new ListNode(head->val);
            return curr;
        }

        ListNode *curr = reverse(head->next);
        ListNode *temp = curr;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        ListNode *currNode = new ListNode(head->val);
        temp->next = currNode;

        return curr;
    }

public:
    void reorderList(ListNode *head)
    {
        ListNode *head2 = reverse(head);

        int n = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            n++;
        }

        int i = 0;
        temp = head;
        ListNode *next = head->next;
        ListNode *next2 = head2->next;
        ListNode *prev = head2;
        while (i < (n) / 2)
        {
            temp->next = head2;
            prev = head2;
            head2->next = next;
            temp = next;
            head2 = next2;
            next = next->next;
            next2 = next2->next;
            i++;
        }

        if (n % 2 != 0)
        {
            temp->next = NULL;
        }
        else
        {
            prev->next = NULL;
        }

        return;
    }
};