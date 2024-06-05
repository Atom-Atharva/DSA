// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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

class Solution
{
    ListNode *reverseLL(ListNode *head)
    {
        // Base Case
        if (head->next == NULL)
        {
            return head;
        }

        // New Head
        ListNode *newHead = reverseLL(head->next);

        // Connect Head to Last
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Initiate Vairable
        ListNode *curr = head, *currHead = head, *prev = NULL, *next = NULL;

        // Iterate on Group
        int i = 1;
        while (curr != NULL)
        {
            if (i == 1)
            {
                currHead = curr;
            }
            if (i == k)
            {
                next = curr->next;
                curr->next = NULL;

                // Recursive Call on Complete Group
                ListNode *newHead = reverseLL(currHead);

                // Make Connections
                // Connect Prev
                if (prev == NULL)
                {
                    head = newHead;
                }
                else
                {
                    prev->next = newHead;
                }

                // Connect Next
                currHead->next = next;

                // Change Current
                curr = currHead;

                // Restore i
                i = 0;

                // Update Prev
                prev = curr;
            }

            curr = curr->next;
            i++;
        }

        return head;
    }
};