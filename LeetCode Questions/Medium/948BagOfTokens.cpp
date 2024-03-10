// https://leetcode.com/problems/bag-of-tokens/?envType=daily-question&envId=2024-03-04

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        // Sort Array
        sort(tokens.begin(), tokens.end());

        // 2 Pointers --> i,j
        int maxScore = 0, score = 0;
        int i = 0, j = tokens.size() - 1;
        while (i <= j)
        {
            if (power >= tokens[i])
            {
                score++;
                maxScore = max(score, maxScore);
                power -= tokens[i];
                i++;
            }
            else
            {
                if (score)
                {
                    score--;
                    maxScore = max(score, maxScore);
                    power += tokens[j];
                    j--;
                }
                else
                {
                    break;
                }
            }
        }

        return maxScore;
    }
};