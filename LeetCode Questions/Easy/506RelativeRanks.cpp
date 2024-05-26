// https://leetcode.com/problems/relative-ranks/description/?envType=daily-question&envId=2024-05-08

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        unordered_map<int, int> index;
        for (int i = 0; i < score.size(); i++)
        {
            index[score[i]] = i;
        }

        sort(score.begin(), score.end(), greater<int>());

        vector<string> rank(score.size());
        for (int i = 0; i < score.size(); i++)
        {
            if (i == 0)
            {
                rank[index[score[i]]] = "Gold Medal";
            }
            else if (i == 1)
            {
                rank[index[score[i]]] = "Silver Medal";
            }
            else if (i == 2)
            {
                rank[index[score[i]]] = "Bronze Medal";
            }
            else
            {
                rank[index[score[i]]] = to_string(i + 1);
            }
        }

        return rank;
    }
};