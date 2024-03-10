// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05

#include <iostream>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i <= j)
        {
            if (s[i] == s[j] && i != j)
            {
                i++;
                j--;
            }
            else
            {
                if (i - 1 >= 0 && s[i - 1] == s[j])
                {
                    j--;
                }
                else if (j + 1 < s.length() && s[i] == s[j + 1])
                {
                    i++;
                }
                else
                {
                    break;
                }
            }
        }

        return j - i + 1;
    }
};
