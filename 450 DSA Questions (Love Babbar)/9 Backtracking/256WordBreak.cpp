// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

// Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word. Each dictionary word can be used more than once. Return all such possible sentences.

// Follow examples for better understanding.

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
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        // Insert words inside map--
        unordered_map<string, bool> words;
        for (int i = 0; i < n; i++)
        {
            words[dict[i]] = 1;
        }

        vector<string> output;
        wordBreak(s, words, output, "");

        return output;
    }
};