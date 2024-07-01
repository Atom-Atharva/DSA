// https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        // Base Case
        if (hand.size() % groupSize != 0)
        {
            return false;
        }

        // Sorted cards
        sort(hand.begin(), hand.end());

        for (int i = 0; i < hand.size(); i++)
        {
            // If Tqken
            if (hand[i] == -1)
            {
                continue;
            }

            int k = 1;
            int prev = hand[i];
            hand[i] = -1;

            for (int j = i + 1; j < hand.size() && k < groupSize; j++)
            {
                if (hand[j] == -1)
                {
                    continue;
                }
                if (hand[j] == prev + 1)
                {
                    k++;
                    prev = hand[j];
                    hand[j] = -1;
                }
                if (hand[j] > prev + 1)
                {
                    return false;
                }
            }
            if (k != groupSize)
            {
                return false;
            }
        }
        return true;
    }
};