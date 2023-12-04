// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=daily-question&envId=2023-12-02

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> umap;
        for (int i = 0; i < chars.length(); i++)
        {
            // Insert chars into Map--
            umap[chars[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            // Temporary Map--
            unordered_map<char, int> temp;
            temp = umap;

            // Itteration on Each word--
            int j = 0;
            for (; j < words[i].size(); j++)
            {
                // Check if word is formable--
                if (temp.count(words[i][j]) && temp[words[i][j]] > 0)
                {
                    temp[words[i][j]]--;
                }
                else
                {
                    break;
                }
            }

            // Add Word if all found--
            if (j == words[i].size())
            {
                ans += words[i].length();
            }
        }

        return ans;
    }
};