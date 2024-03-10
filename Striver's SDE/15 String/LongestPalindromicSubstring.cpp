// https://www.codingninjas.com/studio/problems/day-12-:-longest-palindromic-substring_758900

#include <iostream>
using namespace std;

// Optimization
// Time Complexity --> O(n^2)
string longestPalinSubstring(string str)
{
    string output = "";

    // For Each Character
    for (int i = 0; i < str.length(); i++)
    {
        // Longest Palindrome with Character as Center
        string curr = str.substr(i, 1);

        // Working on ODDs
        int st = i - 1, en = i + 1;
        while (st >= 0 && en < str.length())
        {
            if (str[st] == str[en])
            {
                curr = str[st] + curr + str[en];
                en++, st--;
            }
            else
            {
                break;
            }
        }
        output = (curr.length() > output.length()) ? curr : output;

        // Working on EVENs
        if (i - 1 > 0 && str[i] == str[i - 1])
        {
            curr = str.substr(i - 1, 2);

            int st = i - 2, en = i + 1;
            while (st >= 0 && en < str.length())
            {
                if (str[st] == str[en])
                {
                    curr = str[st] + curr + str[en];
                    en++, st--;
                }
                else
                {
                    break;
                }
            }
            output = (curr.length() > output.length()) ? curr : output;
        }
    }

    return output;
}

// Brute Force Method
// TLE --> O(n^3)
// bool isPalindrome(string str)
// {
//     for (int i = 0; i < str.length() / 2; i++)
//     {
//         if (str[i] != str[str.length() - 1 - i])
//         {
//             return false;
//         }
//     }

//     return true;
// }

// string longestPalinSubstring(string str)
// {
//     string output = "";

//     // Find All Substrings
//     for (int i = 0; i < str.length(); i++)
//     {
//         for (int j = i; j < str.length(); j++)
//         {
//             // Check for Palindrome
//             string curr = str.substr(i, j - i + 1);
//             if (curr.length() > output.length() && isPalindrome(curr))
//             {
//                 output = curr;
//             }
//         }
//     }

//     return output;
// }