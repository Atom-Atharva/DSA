// https://www.geeksforgeeks.org/problems/word-ladder/1

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <climits>

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Gather startIndex of startWord
        int startIndex = -1;
        int endIndex = -1;
        for (int i = 0; i < wordList.size(); i++)
        {
            if (wordList[i] == startWord)
            {
                startIndex = i;
            }
            if (wordList[i] == targetWord)
            {
                endIndex = i;
            }
        }
        if (startIndex == -1)
        {
            wordList.push_back(startWord);
            startIndex = wordList.size() - 1;
        }

        int n = wordList.size();

        // Make Graph with every word (Using Index)
        vector<int> adj[n];

        // Make Adjacency List
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = 0;
                for (int k = 0; k < wordList[i].size(); k++)
                {
                    if (wordList[i][k] != wordList[j][k])
                    {
                        diff++;
                    }
                }

                if (diff == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Calculate Shortest Path from Source
        queue<int> nodes;
        nodes.push(startIndex);

        vector<int> dist(n, INT_MAX);
        dist[startIndex] = 1;
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();

            for (auto itr : adj[node])
            {
                if (dist[node] + 1 < dist[itr])
                {
                    dist[itr] = dist[node] + 1;
                    nodes.push(itr);
                }
            }
        }

        return (dist[endIndex] == INT_MAX) ? 0 : dist[endIndex];
    }
};