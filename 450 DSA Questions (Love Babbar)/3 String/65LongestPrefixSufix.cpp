// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

//**************************************** IMPORTANT QUESTION ***********************************************//

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int lps(string s)
    {
        int n = s.length();
        vector<int> len(n, 0);

        int i = 0, j = 1;
        while (j < n)
        {
            if (s[i] == s[j])
            {
                len[j] = i + 1;
                i++, j++;
            }
            else
            {
                if (i == 0)
                {
                    j++;
                }
                else
                {
                    i = len[i - 1];
                }
            }
        }

        return len[n - 1];
    }
};