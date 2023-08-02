// https://leetcode.com/problems/reorganize-string/

// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

#include <iostream>
using namespace std;
#include <unordered_map>
#include <queue>

// Structure of the condition
// for sorting the pair by its
// second elements
struct myComp
{
    constexpr bool operator()(
        pair<char, int> const &a,
        pair<char, int> const &b)
        const noexcept
    {
        return a.second < b.second;
    }
};

class Solution
{
public:
    string reorganizeString(string s)
    {
        // Calculate Frequency--
        unordered_map<char, int> freq;
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]]++;
        }

        // Max Frequency insertion in HEAP--
        priority_queue<pair<char, int>, vector<pair<char, int>>, myComp> queue;
        for (auto itr : freq)
        {
            queue.push(itr);
        }

        string ans = "";
        char prev = '#';
        while (!queue.empty())
        {
            pair<char, int> temp = queue.top();
            queue.pop();

            if (temp.first == prev)
            {
                if (queue.empty())
                {
                    return "";
                }

                pair<char, int> temp2 = queue.top();
                queue.pop();

                queue.push(temp);
                temp = temp2;
            }

            ans += temp.first;
            prev = temp.first;
            temp.second--;

            if (temp.second != 0)
            {
                queue.push(temp);
            }
        }

        return ans;
    }
};