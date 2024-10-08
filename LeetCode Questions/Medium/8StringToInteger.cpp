// https://leetcode.com/problems/string-to-integer-atoi/

// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

// The algorithm for myAtoi(string s) is as follows:

// Read in and ignore any leading whitespace.
// Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
// Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
// Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
// If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
// Return the integer as the final result.
// Note:

// Only the space character ' ' is considered a whitespace character.
// Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

#include <iostream>
using namespace std;
#include <climits>

class Solution
{
    int num(char c)
    {
        return c - '0';
    }

public:
    int myAtoi(string s)
    {
        bool positive = true;
        bool sign = false;
        bool bre = false;
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' && !sign)
            {
                continue;
            }
            if (s[i] == '-' && !sign)
            {
                positive = false;
                sign = true;
                continue;
            }
            if (s[i] == '+' && !sign)
            {
                sign = true;
                continue;
            }
            if (num(s[i]) > 9 || num(s[i]) < 0)
            {
                break;
            }

            if ((long)ans * 10 + num(s[i]) > INT_MAX)
            {
                ans = INT_MAX;
                bre = true;
                break;
            }
            ans = ans * 10 + num(s[i]);
            sign = true;
        }
        if (ans == INT_MAX && !positive && bre)
        {
            return INT_MIN;
        }
        return (positive) ? ans : -ans;
    }
};