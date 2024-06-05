// https://leetcode.com/problems/find-common-characters/?envType=daily-question&envId=2024-06-05

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        string commonWord = "";
        for (int i = 0; i < words.size(); i++)
        {
            sort(words[i].begin(), words[i].end());
            if (i == 0)
            {
                commonWord = words[i];
                continue;
            }

            string common = "";
            int fir = 0, sec = 0;
            while (fir < commonWord.length() && sec < words[i].length())
            {
                if (commonWord[fir] == words[i][sec])
                {
                    common += commonWord[fir];
                    fir++;
                    sec++;
                }
                else if (commonWord[fir] < words[i][sec])
                {
                    fir++;
                }
                else
                {
                    sec++;
                }
            }

            commonWord = common;
        }

        vector<string> ans;
        for (int i = 0; i < commonWord.length(); i++)
        {
            ans.push_back(string(1, commonWord[i]));
        }

        return ans;
    }
};
