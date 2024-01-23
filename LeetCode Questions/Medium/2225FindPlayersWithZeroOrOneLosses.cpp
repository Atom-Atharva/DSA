// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < matches.size(); i++)
        {
            umap[matches[i][1]]++;
            if (!umap[matches[i][0]])
            {
                umap[matches[i][0]] = 0;
            }
        }

        vector<vector<int>> answer(2);
        for (auto itr : umap)
        {
            if (itr.second == 1)
            {
                answer[1].push_back(itr.first);
            }
            if (itr.second == 0)
            {
                answer[0].push_back(itr.first);
            }
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());

        return answer;
    }
};