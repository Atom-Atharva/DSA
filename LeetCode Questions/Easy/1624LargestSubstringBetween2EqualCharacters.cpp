// https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/?envType=daily-question&envId=2023-12-31

#include <string>
using namespace std;
#include <unordered_map>

class Solution
{
    unordered_map<string, int> umap;

public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        // Base Case
        if (s.size() <= 1)
        {
            return -1;
        }
        if (s[0] == s[s.size() - 1])
        {
            return s.size() - 2;
        }
        if (umap.count(s) > 0)
        {
            return umap[s];
        }

        // Recursive Calls
        int leftReduce = maxLengthBetweenEqualCharacters(s.substr(1));
        int rightReduce = maxLengthBetweenEqualCharacters(s.substr(0, s.size() - 1));

        // Select Maximum
        return umap[s] = max(leftReduce, rightReduce);
    }
};