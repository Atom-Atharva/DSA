// https://leetcode.com/problems/linked-list-cycle/

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

//  Definition for singly-linked list.

#include <iostream>
using namespace std;
#include <climits>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Optimized Solution--
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};

// Naive Solution--
//  class Solution
//  {
//  public:
//      bool hasCycle(ListNode *head)
//      {
//          if (head == NULL)
//          {
//              return false;
//          }
//          if (head->val == INT_MIN)
//          {
//              return true;
//          }

//         head->val = INT_MIN;
//         bool ans = hasCycle(head->next);
//         if(ans){
//             return true;
//         }
//         return false;
//     }
// };