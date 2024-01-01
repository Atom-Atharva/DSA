// https://practice.geeksforgeeks.org/problems/pattern-searching4145/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int search(string text, string pat)
    {
        for (int i = 0; i < text.size(); i++)
        {
            bool found = true;
            int temp = i;
            for (int j = 0; j < pat.size(); j++)
            {
                if (pat[j] != text[temp])
                {
                    found = false;
                    break;
                }
                temp++;
            }
            if (found)
            {
                return 1;
            }
        }

        return 0;
    }
};