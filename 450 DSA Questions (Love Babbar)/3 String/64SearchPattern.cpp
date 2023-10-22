// https://practice.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> search(string pat, string txt)
    {
        vector<int> positions;

        for (int i = 0; i < txt.size() - pat.size() + 1; i++)
        {
            if (txt.substr(i, pat.length()) == pat)
            {
                positions.push_back(i + 1);
            }
        }

        if (positions.size() == 0)
        {
            positions.push_back(-1);
        }

        return positions;
    }
};