#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    long long countCompleteDayPairs(vector<int> &hours)
    {
        unordered_map<int, int> umap;

        for (int i = 0; i < hours.size(); i++)
        {
            umap[hours[i] % 24]++;
        }

        // Handle 0s
        long long count = ((long long)umap[0] * (umap[0] - 1)) / 2;

        for (int i = 1; i <= 12; i++)
        {
            if (i == 12)
            {
                count += (umap[i] * (umap[i] - 1)) / 2;
                continue;
            }

            count += (umap[i] * umap[24 - i]);
        }

        return count;
    }
};