// https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

#include <iostream>
using namespace std;
#include <vector>

//  Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }

        vector<pair<int, int>> ans;

        Node *start = head;
        while (start->data < last->data)
        {
            if ((start->data + last->data) == target)
            {
                ans.push_back({start->data, last->data});
                start = start->next;
                last = last->prev;
            }
            else if ((start->data + last->data) > target)
            {
                last = last->prev;
            }
            else
            {
                start = start->next;
            }
        }

        return ans;
    }
};