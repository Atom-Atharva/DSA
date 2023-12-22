// https://leetcode.com/problems/valid-anagram/description/?envType=daily-question&envId=2023-12-16

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        // Compare Frequency Arrays--
        vector<int> arr_s(26, 0);
        vector<int> arr_t(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            arr_s[s[i] - 'a']++;
            arr_t[t[i] - 'a']++;
        }

        return (arr_s == arr_t) ? true : false;
    }
};