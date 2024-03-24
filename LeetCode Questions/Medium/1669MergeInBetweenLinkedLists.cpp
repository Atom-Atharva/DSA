// https://leetcode.com/problems/merge-in-between-linked-lists/?envType=daily-question&envId=2024-03-20

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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *head = list1;
        int i = 0;
        while (i < a - 1)
        {
            head = head->next;
            i++;
        }

        ListNode *temp = head;
        head = head->next;
        i++;
        temp->next = list2;

        ListNode *head2 = list2;
        while (head2->next != NULL)
        {
            head2 = head2->next;
        }
        while (i < b)
        {
            head = head->next;
            i++;
        }

        head2->next = head->next;
        head->next = NULL;

        return list1;
    }
};