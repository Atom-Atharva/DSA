// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

#include <iostream>
using namespace std;
#include <stack>

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        stack<int> data;

        Node *temp = head;
        while (temp != NULL)
        {
            data.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while (!data.empty() && temp != NULL)
        {
            if (temp->data != data.top())
            {
                return false;
            }
            temp = temp->next;
            data.pop();
        }

        return true;
    }
};