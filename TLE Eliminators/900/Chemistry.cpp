// https://codeforces.com/problemset/problem/1883/B

#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> chars(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            chars[s[i]-'a']++;
        }

        // Try to Make All Even
        for (int i = 0; i < 26 && k > 0; i++)
        {
            if (chars[i] % 2 != 0)
            {
                k--;
                chars[i]--;
            }
        }

        // If still K left
        for (int i = 0; i < 26 && k > 0; i++)
        {
            if (k <= chars[i])
            {
                chars[i] -= k;
                k = 0;
            }
            else
            {
                k -= chars[i];
                chars[i] = 0;
            }
        }

        // Check Palindrome
        int odds = 0;
        for (int i = 0; i < 26; i++)
        {
            if (chars[i] % 2 == 1)
            {
                odds++;
            }
        }

        (odds > 1) ? cout << "No\n" : cout << "Yes\n";
    }
    return 0;
}