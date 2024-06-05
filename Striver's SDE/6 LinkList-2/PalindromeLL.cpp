// https://leetcode.com/problems/palindrome-linked-list/description/

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
    ListNode *node;

    bool isPalindromeHelper(ListNode *head)
    {
        if (head == NULL)
        {
            return true;
        }

        bool answer = isPalindromeHelper(head->next);
        if (!answer)
        {
            return false;
        }

        if (head->val == node->val)
        {
            node = node->next;
            return true;
        }
        return false;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        node = head;

        return isPalindromeHelper(head);
    }
};