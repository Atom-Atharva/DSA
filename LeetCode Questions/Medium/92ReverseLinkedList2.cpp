// https://leetcode.com/problems/reverse-linked-list-ii/

// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

//   Definition for singly-linked list.

#include <iostream>
using namespace std;
#include <stack>

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        stack<ListNode *> nodes;

        // Place Nodes in Stack--
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        int pos = 1;
        while (temp != NULL)
        {
            // Store Prev--
            if (pos == left - 1)
            {
                prev = temp;
            }

            // Store Current--
            if (pos >= left && pos <= right)
            {
                nodes.push(temp);
            }

            // Store Next--
            if (pos == right + 1)
            {
                next = temp;
            }

            temp = temp->next;
            pos++;
        }

        while (!nodes.empty())
        {
            temp = nodes.top();
            nodes.pop();

            if (prev != NULL)
            {
                prev->next = temp;
            }
            else
            {
                head = temp;
            }
            prev = temp;
        }

        prev->next = next;

        return head;
    }
};