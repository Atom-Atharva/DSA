// https://leetcode.com/problems/valid-palindrome-ii/description/

#include <iostream>
using namespace std;

class Solution
{
    bool checkPalindrome(string s, int st, int en)
    {
        while (st < en)
        {
            if (s[st] != s[en])
            {
                return false;
            }
            st++, en--;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int st = 0, en = s.length() - 1;
        while (st < en)
        {
            if (s[st] == s[en])
            {
                st++, en--;
            }
            else
            {
                bool palindrome = false;
                if (s[st + 1] == s[en])
                {
                    palindrome = palindrome || checkPalindrome(s, st + 1, en);
                }
                else if (s[st] == s[en - 1])
                {
                    palindrome = palindrome || checkPalindrome(s, st, en - 1);
                }
                else if (s[st + 1] != s[en] && s[st] != s[en - 1])
                {
                    return false;
                }
                return palindrome;
            }
        }
        return true;
    }
};