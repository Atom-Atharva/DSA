// https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

#include <string>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> letters;
        for (int i = 0; i < magazine.length(); i++)
        {
            letters[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (letters.count(ransomNote[i]) == 0 || letters[ransomNote[i]] == 0)
            {
                return false;
            }
            letters[ransomNote[i]]--;
        }

        return true;
    }
};