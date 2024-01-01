// https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string word = "";
        for (int i = 0; i < s.length(); i++)
        {
            // Decline Leading white spaces
            if (s[i] == ' ' && word == "")
            {
                continue;
            }

            if (s[i] == ' ')
            {
                string reversed = reverseWords(s.substr(i + 1));
                string space = (reversed != "") ? " " : "";
                // reversed = (reversed == " ") ? "" : reversed;

                return reversed + space + word;
            }
            word += s[i];
        }

        return word;
    }
};