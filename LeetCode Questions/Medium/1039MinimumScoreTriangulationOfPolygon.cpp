// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Dynamic Programming
class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        // Dynamic Table + Initialisation
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), 0));

        for (int i = 2; i < values.size(); i++)
        {
            for (int j = 0; j < values.size() - i; j++)
            {
                int min_score = INT_MAX;
                for (int k = j + 1; k < i + j; k++)
                {
                    int curr_score = values[j] * values[i + j] * values[k];

                    // Recursive  Calls--
                    int left = dp[j][k];
                    int right = dp[k][i + j];

                    int score = curr_score + left + right;

                    min_score = min(min_score, score);
                }

                dp[j][i + j] = (min_score == INT_MAX) ? 0 : min_score;
            }
        }

        return dp[0][values.size() - 1];
    }
};

// Recursion + Memomization
class Solution
{
    int minScoreTriangulation(vector<int> &values, int st, int en, vector<vector<int>> &dp)
    {
        if (dp[st][en] != -1)
        {
            return dp[st][en];
        }

        // First and Last is taken as base
        int min_score = INT_MAX;
        for (int i = st + 1; i < en; i++)
        {
            int curr_score = values[st] * values[en] * values[i];

            // Recursive  Calls--
            int left = minScoreTriangulation(values, st, i, dp);
            int right = minScoreTriangulation(values, i, en, dp);

            int score = curr_score + left + right;

            min_score = min(min_score, score);
        }

        return dp[st][en] = (min_score == INT_MAX) ? 0 : min_score;
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));

        return minScoreTriangulation(values, 0, values.size() - 1, dp);
    }
};