// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=study-plan-v2&envId=top-interview-150

#include <string>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<string> numbers;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                // Take Out 2 Numbers--
                int n1 = stoi(numbers.top());
                numbers.pop();
                int n2 = stoi(numbers.top());
                numbers.pop();

                // Push to Stack--
                numbers.push(to_string(n2 + n1));

                continue;
            }
            if (tokens[i] == "-")
            {
                // Take Out 2 Numbers--
                int n1 = stoi(numbers.top());
                numbers.pop();
                int n2 = stoi(numbers.top());
                numbers.pop();

                // Push to Stack--
                numbers.push(to_string(n2 - n1));
                continue;
            }
            if (tokens[i] == "/")
            {
                // Take Out 2 Numbers--
                int n1 = stoi(numbers.top());
                numbers.pop();
                int n2 = stoi(numbers.top());
                numbers.pop();

                // Push to Stack--
                numbers.push(to_string(n2 / n1));
                continue;
            }
            if (tokens[i] == "*")
            {
                // Take Out 2 Numbers--
                int n1 = stoi(numbers.top());
                numbers.pop();
                int n2 = stoi(numbers.top());
                numbers.pop();

                // Push to Stack--
                numbers.push(to_string(n2 * n1));
                continue;
            }

            numbers.push(tokens[i]);
        }

        return stoi(numbers.top());
    }
};