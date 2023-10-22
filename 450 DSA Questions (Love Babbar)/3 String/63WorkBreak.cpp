// https://practice.geeksforgeeks.org/problems/word-break1352/1

// A : given string to search
// B : vector of available strings

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
    bool wordBreak(string A, unordered_map<string, bool> &umap)
    {
        // Base Case--
        if (A.size() == 0)
        {
            return 1;
        }

        // Recursion Call--
        string word = "";
        for (int i = 0; i < A.size(); i++)
        {
            word += A[i];
            if (umap.count(word) > 0)
            {
                bool temp = wordBreak(A.substr(i+1), umap);
                if (temp)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    int wordBreak(string A, vector<string> &B)
    {
        // Map--
        unordered_map<string, bool> umap;
        for (int i = 0; i < B.size(); i++)
        {
            umap[B[i]] = 1;
        }

        // Function Call--
        bool ans = wordBreak(A, umap);
        if (ans)
        {
            return 1;
        }
        return 0;
    }
};