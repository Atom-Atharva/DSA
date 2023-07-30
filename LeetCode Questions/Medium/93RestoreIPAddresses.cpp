// https://leetcode.com/problems/restore-ip-addresses/

// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    // Convert string to integer--
    int strToInt(string str)
    {
        int ans = 0;
        for (int i = 0; i < str.length(); i++)
        {
            ans = ans * 10 + (str[i] - '0');
        }

        return ans;
    }

    // Backtracking Helper Function--
    void ipAddress(string s, vector<string> &output, string path, int integers)
    {
        // Base Case--
        if (s.size() == 0 && integers == 0)
        {
            // Add to output--
            output.push_back(path);
            return;
        }
        if (s.size() == 0 || integers == 0)
        {
            // Dont Add to output--
            return;
        }

        // Recursive Call--
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            // Give to temp--
            temp += s[i];
            if (strToInt(temp) > 255)
            {
                break;
            }

            // Upgrade Path--
            string str = path + temp;
            (integers != 1) ? str += "." : str = str;
            ipAddress(s.substr(i + 1), output, str, integers - 1);

            if (strToInt(temp) == 0)
            {
                break;
            }
        }

        return;
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> output;
        string path = "";
        ipAddress(s, output, path, 4);

        return output;
    }
};