// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/?envType=daily-question&envId=2024-01-23

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

// Recursive Appraoch
class Solution
{
    bool isUnique(string a, string b)
    {
        unordered_map<char, bool> umap;
        for (int i = 0; i < a.length(); i++)
        {
            if (umap[a[i]])
            {
                return false;
            }
            umap[a[i]] = 1;
        }

        for (int i = 0; i < b.length(); i++)
        {
            if (umap[b[i]])
            {
                return false;
            }
            umap[b[i]] = 1;
        }

        return true;
    }

    int maxLength(vector<string> &arr, int pos, string ans)
    {
        // Base Case
        if (arr.size() == pos)
        {
            return 0;
        }

        // Recursive Calls
        // - INCLUDE
        int include = 0;
        if (isUnique(arr[pos], ans))
        {
            include = arr[pos].length() + maxLength(arr, pos + 1, ans + arr[pos]);
        }

        // - EXCLUDE
        int exclude = maxLength(arr, pos + 1, ans);

        return max(include, exclude);
    }

public:
    int maxLength(vector<string> &arr)
    {
        return maxLength(arr, 0, "");
    }
};