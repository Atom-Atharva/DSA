// https://leetcode.com/problems/palindrome-linked-list/?envType=daily-question&envId=2024-03-22

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
    string formString(ListNode *head)
    {
        string ans = "";
        while (head != NULL)
        {
            ans += head->val;
            head = head->next;
        }

        return ans;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        string str = formString(head);

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != str[str.length() - i - 1])
            {
                return false;
            }
        }

        return true;
    }
};