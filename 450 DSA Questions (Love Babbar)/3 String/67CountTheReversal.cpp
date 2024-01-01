// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1

#include <string>
using namespace std;
#include <stack>

int countRev(string s)
{
    stack<char> brackets;

    int reverse = 0;
    // Iterate Over String
    for (int i = 0; i < s.length(); i++)
    {
        // Open Bracket --> Push to Stack
        if (s[i] == '{')
        {
            brackets.push('{');
        }

        // Close Bracket --> Remove from Stack if possible else Reverse
        if (s[i] == '}')
        {
            if (!brackets.empty())
            {
                brackets.pop();
            }
            else
            {
                brackets.push('{');
                reverse++;
            }
        }
    }

    // Check Stack Empty --> If not then Reverse.
    if (!brackets.empty())
    {
        if (brackets.size() % 2 != 0)
        {
            return -1;
        }
        reverse += brackets.size() / 2;
    }

    return reverse;
}