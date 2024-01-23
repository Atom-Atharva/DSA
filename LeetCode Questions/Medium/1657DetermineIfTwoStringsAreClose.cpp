// https://leetcode.com/problems/determine-if-two-strings-are-close/?envType=daily-question&envId=2024-01-14

#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // Base Case--
        if (word1.length() != word2.length())
        {
            return false;
        }

        unordered_map<char, int> w1map, w2map;
        unordered_map<char, bool> umap1, umap2;
        for (int i = 0; i < word1.length(); i++)
        {
            w1map[word1[i]]++;
            w2map[word2[i]]++;
            umap1[word1[i]] = 1;
            umap2[word2[i]] = 1;
        }

        if (umap1 != umap2)
        {
            return false;
        }

        vector<int> w1arr, w2arr;
        for (auto itr : w1map)
        {
            w1arr.push_back(itr.second);
        }
        for (auto itr : w2map)
        {
            w2arr.push_back(itr.second);
        }

        sort(w1arr.begin(), w1arr.end());
        sort(w2arr.begin(), w2arr.end());

        return (w1arr == w2arr);
    }
};