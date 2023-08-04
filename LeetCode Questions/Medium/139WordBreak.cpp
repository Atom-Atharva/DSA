// https://leetcode.com/problems/word-break/

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
    bool wordBreak(string s, unordered_map<string, bool> &words, vector<int> &dp)
    {
        // Base Case--
        if (s.length() == 0)
        {
            return true;
        }
        if (dp[s.length()] != -1)
        {
            return dp[s.length()];
        }

        // Recursive Calls--
        string word = "";
        bool check = false;
        for (int i = 0; i < s.length(); i++)
        {
            word += s[i];

            if (words.count(word) > 0)
            {
                check = wordBreak(s.substr(i + 1), words, dp);
                if (check)
                {
                    break;
                }
            }
        }

        return dp[s.length()] = (int)check;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // Push words inside map--
        unordered_map<string, bool> words;

        for (int i = 0; i < wordDict.size(); i++)
        {
            words[wordDict[i]] = 1;
        }

        vector<int> dp(s.length() + 1, -1);

        bool check = wordBreak(s, words, dp);

        return check;
    }
};