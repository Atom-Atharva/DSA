// https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string lookandsay(int n)
    {
        // Base Case
        if (n == 1)
        {
            return "1";
        }

        string s = lookandsay(n - 1);
        string ans = "";

        int count = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
            {
                count++;
                continue;
            }

            ans += to_string(count) + s[i - 1];
            count = 1;
        }
        ans += to_string(count) + s[s.length() - 1];

        return ans;
    }
};
