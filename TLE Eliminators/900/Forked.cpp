// https://codeforces.com/problemset/problem/1904/A

#include <iostream>
using namespace std;
#include <set>
#include <vector>

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int a, b;
        cin >> a >> b;

        int xk, yk;
        cin >> xk >> yk;

        int xq, yq;
        cin >> xq >> yq;

        // Get all combinations
        set<pair<int, int>> umap;
        vector<int> x = {a, b, a, b, -a, -b, -a, -b};
        vector<int> y = {b, a, -b, -a, b, a, -b, -a};

        for (int i = 0; i < 8; i++)
        {
            int nx = xk + x[i];
            int ny = yk + y[i];

            umap.insert({nx, ny});
        }

        int count = 0;
        for (int i = 0; i < 8; i++)
        {
            int nx = xq + x[i];
            int ny = yq + y[i];

            if (umap.find({nx, ny}) != umap.end())
            {
                umap.erase({nx, ny});
                count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}