// https://leetcode.com/problems/isomorphic-strings/?envType=study-plan-v2&envId=top-interview-150

#include <string>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, char> map;
        unordered_map<char, char> map2;
        for (int i = 0; i < s.length(); i++)
        {
            if (map.count(s[i]) > 0)
            {
                if (map[s[i]] != t[i])
                {
                    return false;
                }
            }
            if (map2.count(t[i]) > 0)
            {
                if (map2[t[i]] != s[i])
                {
                    return false;
                }
            }
            map[s[i]] = t[i];
            map2[t[i]] = s[i];
        }

        return true;
    }
};