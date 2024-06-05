// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA != NULL && tempB != NULL)
        {
            if (tempA == tempB)
            {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        if (tempA == NULL && tempB == NULL)
        {
            return NULL;
        }

        bool isA = false;
        if (tempA == NULL)
        {
            isA = true;
            tempA = headB;
        }
        else
        {
            tempB = headA;
        }
        while (tempA != NULL && tempB != NULL)
        {
            if (tempA == tempB)
            {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;

            if (isA && tempB == NULL)
            {
                tempB = headA;
            }
            if (!isA && tempA == NULL)
            {
                tempA = headB;
            }
        }

        return NULL;
    }
};