// https://leetcode.com/problems/word-pattern/?envType=study-plan-v2

// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> word;

        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                word.push_back(temp);
                temp = "";
                continue;
            }
            temp += s[i];
        }
        word.push_back(temp);

        if (word.size() != pattern.length())
        {
            return false;
        }

        unordered_map<char, int> map1;
        unordered_map<string, int> map2;

        for (int i = 0; i < pattern.size(); i++)
        {
            if (map1.count(pattern[i]) == 0 && map2.count(word[i]) == 0)
            {
                map1[pattern[i]] = i;
                map2[word[i]] = i;
                continue;
            }
        
            if (map1.count(pattern[i]) == 0 || map2.count(word[i]) == 0 || map1[pattern[i]] != map2[word[i]])
            {
                return false;
            }

            map1[pattern[i]] = i;

            map2[word[i]] = i;
        }

        return true;
    }
};