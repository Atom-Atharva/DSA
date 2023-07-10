// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

// Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    void swap(string &S, int pos1, int pos2)
    {
        // Swap Using 3rd Variable--
        char temp = S[pos1];
        S[pos1] = S[pos2];
        S[pos2] = temp;

        return;
    }

    void permutation(string S, vector<string> &ans, int pos)
    {
        // Base Case--
        if (pos == S.size() - 1)
        {
            ans.push_back(S);
            return;
        }

        // From curr element to last element--
        for (int i = pos; i < S.size(); i++)
        {
            // If Repeated--
            if (i < S.size() - 1 && S[i] == S[i + 1])
            {
                continue;
            }

            // Swap--
            swap(S, pos, i);

            // Recursion--
            permutation(S, ans, pos + 1);
        }

        return;
    }

public:
    vector<string> find_permutation(string S)
    {
        vector<string> ans;

        // Sort Given String--
        sort(S.begin(), S.end());

        // Gather Permutations--
        permutation(S, ans, 0);

        // Sort String for lexicographically string--
        sort(ans.begin(), ans.end());

        // final Ans--
        vector<string> fans;
        for (int i = 0; i < ans.size(); i++)
        {
            if (i < ans.size() - 1 && ans[i] == ans[i + 1])
            {
                continue;
            }
            fans.push_back(ans[i]);
        }

        return fans;
    }
};

int main()
{
    string S;
    cin >> S;

    Solution obj;
    vector<string> ans = obj.find_permutation(S);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}