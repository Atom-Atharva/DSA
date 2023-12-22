// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2023-12-22

#include <string>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        // Count ones and zeros--
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < s.length(); i++)
        {
            (s[i] == '1') ? ones++ : zeros++;
        }

        // Left Window Increases every itteration
        int left = (s[0] == '0') ? 1 : 0;
        int right = (s[0] == '0') ? ones : ones - 1;
        int score = left + right;
        for (int i = 1; i < s.length() - 1; i++)
        {
            if (s[i] == '0')
            {
                left++;
            }
            else
            {
                right--;
            }
            int curr = left + right;
            score = max(score, curr);
        }

        return score;
    }
};