// https://www.codingninjas.com/studio/problems/696444?topList=striver-sde-sheet-problems

#include <iostream>
using namespace std;
#include <stack>

string reverseString(string &str)
{
    stack<string> words;

    string word = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            if (word != "")
            {
                words.push(word);
                word = "";
            }
        }
        else
        {
            word += str[i];
        }
    }
    if (word != "")
    {
        words.push(word);
    }

    string ans = "";
    while (!words.empty())
    {
        ans += words.top();
        words.pop();

        ans += " ";
    }

    return ans.substr(0, ans.length() - 1);
}