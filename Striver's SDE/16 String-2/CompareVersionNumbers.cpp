// https://leetcode.com/problems/compare-version-numbers/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<long long int> v1;
        vector<long long int> v2;

        long long int s = 0;
        for (int i = 0; i < version1.length(); i++)
        {
            if (version1[i] == '.')
            {
                v1.push_back(s);
                s = 0;
            }
            else
            {
                s = s * 10 + version1[i] - '0';
            }
        }
        v1.push_back(s);

        s = 0;
        for (int i = 0; i < version2.length(); i++)
        {
            if (version2[i] == '.')
            {

                v2.push_back(s);
                s = 0;
            }
            else
            {
                s = s * 10 + version2[i] - '0';
            }
        }
        v2.push_back(s);

        // Compare
        for (int i = 0; i < v1.size() || i < v2.size(); i++)
        {
            long long int n1 = (i < v1.size()) ? v1[i] : 0;
            long long int n2 = (i < v2.size()) ? v2[i] : 0;

            if (n1 < n2)
            {
                return -1;
            }
            else if (n1 > n2)
            {
                return 1;
            }
        }

        return 0;
    }
};