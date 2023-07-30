// https://leetcode.com/problems/decode-ways/

// A message containing letters from A-Z can be encoded into numbers using the following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

// Given a string s containing only digits, return the number of ways to decode it.

// The test cases are generated so that the answer fits in a 32-bit integer.

#include <iostream>
using namespace std;
#include <vector>

// Method: 2
// Memomization
class Solution
{
    int sti(string curr)
    {
        int ans = 0;
        for (int i = 0; i < curr.size(); i++)
        {
            ans = ans * 10 + (curr[i] - '0');
        }

        return ans;
    }

    int numDecodings(string s, string curr, vector<vector<int>> &seen)
    {
        // Base Case--
        int character = sti(curr);
        if (curr.size() != 0 && (character > 26 || character <= 0))
        {
            return 0;
        }
        if (s.size() == 0)
        {
            return 1;
        }
        if (seen[s.length()][curr.length()] != -1)
        {
            return seen[s.length()][curr.length()];
        }

        // Recursive Call--
        // Take
        int take = 0;
        if (curr.length() != 0)
        {
            string temp = s.substr(0, 1);
            take = numDecodings(s.substr(1), temp, seen);
        }

        // Dont Take
        int ignore = numDecodings(s.substr(1), curr + s[0], seen);

        // Small Calculation
        return seen[s.length()][curr.length()] = take + ignore;
    }

public:
    int numDecodings(string s)
    {
        vector<vector<int>> seen(s.length() + 1, vector<int>(s.length() + 1, -1));
        return numDecodings(s, "", seen);
    }
};

// Method: 1
// Recursive Approach
// class Solution
// {
//     int sti(string curr)
//     {
//         int ans = 0;
//         for (int i = 0; i < curr.size(); i++)
//         {
//             ans = ans * 10 + (curr[i] - '0');
//         }

//         return ans;
//     }

// public:
//     int numDecodings(string s, string curr = "")
//     {
//         // Base Case--
//         int character = sti(curr);
//         if (curr.size() != 0 && (character > 26 || character <= 0))
//         {
//             return 0;
//         }
//         if (s.size() == 0)
//         {
//             return 1;
//         }

//         // Recursive Call--

//         // Take
//         int take = 0;
//         if (curr.length() != 0)
//         {
//             string temp = s.substr(0, 1);
//             take = numDecodings(s.substr(1), temp);
//         }

//         // Dont Take
//         int ignore = numDecodings(s.substr(1), curr + s[0]);

//         // Small Calculation
//         return take + ignore;
//     }
// };