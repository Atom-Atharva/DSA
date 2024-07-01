// https://leetcode.com/problems/replace-words/description/?envType=daily-question&envId=2024-06-07

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_map<string, bool> umap;
        for (int i = 0; i < dictionary.size(); i++)
        {
            umap[dictionary[i]] = 1;
        }

        string word = "";
        string replaced = "";
        for (int i = 0; i < sentence.length(); i++)
        {
            word += sentence[i];

            if (sentence[i] == ' ')
            {
                replaced += word;
                word = "";
            }
            if (umap.count(word) > 0)
            {
                replaced += word;
                word = "";
                while (i < sentence.length() && sentence[i] != ' ')
                {
                    i++;
                }
                if (i < sentence.length() && sentence[i] == ' ')
                {
                    replaced += " ";
                }
            }
        }
        if (word != "")
        {
            replaced += word;
        }

        return replaced;
    }
};