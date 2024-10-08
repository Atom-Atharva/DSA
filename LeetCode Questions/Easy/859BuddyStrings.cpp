// https://leetcode.com/problems/buddy-strings/

// Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

// Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

// For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        // Not Equal Length--
        if (s.length() != goal.length())
        {
            return false;
        }

        // Calculate Variables--
        unordered_map<char, int> seen;
        unordered_map<char, int> available;
        int count = 0;
        bool duplicate = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
            {
                count++;
            }
            seen[s[i]]++;
            available[goal[i]]++;

            if (seen[s[i]] > 1)
            {
                duplicate = 1;
            }
        }

        // Conditions--
        if (seen != available)
        {
            return false;
        }
        if (count == 2)
        {
            return true;
        }
        if (count == 0)
        {
            if (duplicate)
            {
                return true;
            }
        }

        return false;
    }
};