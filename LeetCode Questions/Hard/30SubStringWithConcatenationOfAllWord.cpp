// https://leetcode.com/problems/substring-with-concatenation-of-all-words/?envType=study-plan-v2&envId=top-interview-150

#include <string>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        // Find Window Size for the string == words[0].size();
        int winSize = words[0].size();

        // Map for Available Words
        unordered_map<string, int> allWords;
        for (int i = 0; i < words.size(); i++)
        {
            allWords[words[i]]++;
        }

        // Iterate over string
        vector<int> index;
        for (int i = 0; i < s.length() && s.length() - i >= winSize * words.size(); i++)
        {
            unordered_map<string, int> availableWords = allWords;
            unordered_map<string, int> checkedWords;
            bool found = true;
            // Check for Substrings
            for (int j = i; j < s.length(); j += winSize)
            {
                // Find Windowed word in available map.
                string windowWord = s.substr(j, winSize);

                if (availableWords.count(windowWord) == 0 || availableWords[windowWord] == 0)
                {
                    found = false;
                    break;
                }
                availableWords[windowWord]--;
                checkedWords[windowWord]++;
                if (checkedWords == allWords)
                {
                    break;
                }
            }
            if (found && checkedWords == allWords)
            {
                index.push_back(i);
            }
        }

        return index;
    }
};