// https://practice.geeksforgeeks.org/problems/power-set4302/1

// Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order

#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <algorithm>

/******************** GOOD CONCEPT **********************/

// Method 1: Simple Recursion.

// Method 2: Bit Wise Operations.
class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> ans;
        int n = pow(2, s.length());

        for (int i = 1; i < n; i++)
        {
            string str = "";
            int pos = 0;
            int run = i;

            while (run)
            {
                if (run & 1)
                {
                    str += s[pos];
                }
                pos++;
                run = run >> 1;
            }
            ans.push_back(str);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
