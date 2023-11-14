// https://leetcode.com/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2023-11-13

#include <iostream>
using namespace std;
#include <unordered_map>
#include <algorithm>
#include <vector>

//**** Intresting Learning: String and Character Array don't share same bits size for same length of word ****//

class Solution
{
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    string sortVowels(string s)
    {
        // Form Vowels String--
        // string vowels;
        vector<char> vowels;
        for (int i = 0; i < s.length(); i++)
        {
            if (isVowel(tolower(s[i])))
            {
                // vowels = vowels + s[i];
                vowels.push_back(s[i]);
            }
        }

        // Base Cases--
        // if (vowels.empty())
        // {
        //     return s;
        // }

        // Sort Vowels String--
        sort(vowels.begin(), vowels.end());

        // Base Case 2--
        // if (vowels.size() == s.length())
        // {
        //     return vowels;
        // }

        // Reframe ans String--
        for (int i = 0, st = 0; i < s.length(); i++)
        {
            if (isVowel(tolower(s[i])))
            {
                s[i] = vowels[st++];
            }
        }

        return s;
    }
};