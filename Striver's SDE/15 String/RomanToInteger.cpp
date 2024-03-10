// https://www.codingninjas.com/studio/problems/roman-numeral-to-integer_981308

#include <iostream>
using namespace std;

int roman(char c)
{
    if (c == 'I')
    {
        return 1;
    }
    else if (c == 'V')
    {
        return 5;
    }
    else if (c == 'X')
    {
        return 10;
    }
    else if (c == 'L')
    {
        return 50;
    }
    else if (c == 'C')
    {
        return 100;
    }
    else if (c == 'D')
    {
        return 500;
    }
    else
    {
        return 1000;
    }
}

int romanToInt(string s)
{
    int ans = 0;
    int prev = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int value = roman(s[i]);

        if (prev < value)
        {
            ans = ans - (2 * prev);
        }
        ans = ans + value;
        prev = value;
    }

    return ans;
}