// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Base Case
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }

        ListNode *newHead = NULL;
        ListNode *curr = newHead;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                if (curr == NULL)
                {
                    newHead = list1;
                    curr = newHead;
                }
                else
                {
                    curr->next = list1;
                    curr = curr->next;
                }

                list1 = list1->next;
            }
            else
            {
                if (curr == NULL)
                {
                    newHead = list2;
                    curr = newHead;
                }
                else
                {
                    curr->next = list2;
                    curr = curr->next;
                }

                list2 = list2->next;
            }
        }

        if (list1)
        {
            curr->next = list1;
        }
        if (list2)
        {
            curr->next = list2;
        }

        return newHead;
    }
};