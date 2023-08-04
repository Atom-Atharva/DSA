// https://leetcode.com/problems/word-break-ii/

// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
    void wordBreak(string s, unordered_map<string, bool> words, vector<string> &output, string str)
    {
        // Base Case--
        if (s.length() == 0)
        {
            output.push_back(str.substr(0, str.length() - 1));
            return;
        }

        // Recursive Call--
        string word = "";
        for (int i = 0; i < s.length(); i++)
        {
            word += s[i];
            if (words.count(word) > 0)
            {
                string temp = str + word + " ";
                wordBreak(s.substr(i + 1), words, output, temp);
            }
        }
        return;
    }

public:
    vector<string> wordBreak(string s, vector<string> &dict)
    {
        // Insert words inside map--
        unordered_map<string, bool> words;
        for (int i = 0; i < dict.size(); i++)
        {
            words[dict[i]] = 1;
        }

        vector<string> output;
        wordBreak(s, words, output, "");

        return output;
    }
};