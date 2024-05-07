// https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        // Sort
        sort(deck.begin(), deck.end());

        // ReOrder Vector
        vector<int> reorder(deck.size(), -1);

        // Queue to store position not element
        queue<int> que;
        for (int i = 0; i < deck.size(); i++)
        {
            que.push(i);
        }

        // Put element at position from the queue
        // Only even positons will be placed and odd ones will be queued back
        bool even = true;
        int i = 0;
        while (!que.empty())
        {
            int pos = que.front();
            que.pop();

            if (even)
            {
                reorder[pos] = deck[i];
                i++;
            }
            else
            {
                que.push(pos);
            }
            even = !even;
        }

        return reorder;
    }
};