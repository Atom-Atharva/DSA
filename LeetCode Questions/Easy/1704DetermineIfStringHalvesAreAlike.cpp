// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-01-12

#include <string>
using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int vowels = 0;
        for (int i = 0; i < s.length() / 2; i++)
        {
            char curr = tolower(s[i]);

            if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u')
            {
                vowels++;
            }
        }

        for (int i = s.length() / 2; i < s.length(); i++)
        {
            char curr = tolower(s[i]);

            if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u')
            {
                vowels--;
            }
        }

        return (vowels == 0);
    }
};