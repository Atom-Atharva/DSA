// https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        // Form Intervals--
        vector<pair<long long, long long>> intervals;
        for (int i = 0; i < n; i++)
        {
            long long a, b;
            cin >> a >> b;

            intervals.push_back({a, b});
        }

        // Sort Intervals--
        sort(intervals.begin(), intervals.end());

        // Combine Intervals--
        long long st = intervals[0].first;
        long long en = intervals[0].second;
        vector<pair<long long, long long>> merged;
        for (int i = 1; i < intervals.size(); i++)
        {
            long long curr_st = intervals[i].first;
            long long curr_en = intervals[i].second;

            // Merge Intervals--
            if (curr_st <= en)
            {
                if (curr_en > en)
                {
                    en = curr_en;
                }
            }
            else
            {
                merged.push_back({st, en});
                st = curr_st;
                en = curr_en;
            }
        }
        merged.push_back({st, en});

        for (int i = 0; i < q; i++)
        {
            long long k;
            cin >> k;

            // Find Kth Smallest--
            int j;
            for (j = 0; j < merged.size(); j++)
            {
                long long range = merged[j].second - merged[j].first + 1;

                // Check Kth Smallest Value in Current Interval--
                if (range >= k)
                {
                    cout << merged[j].first + k - 1 << endl;
                    break;
                }
                else
                {
                    k = k - range;
                }
            }

            // If K is not possible--
            if (k > 0 && j >= merged.size())
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}

// Method 1: Memory Limit Exceeded.
/*
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<long long> arr;
        unordered_map<long long, bool> umap;
        for (int i = 0; i < n; i++)
        {
            long long a, b;
            cin >> a >> b;

            for (long long j = a; j <= b; j++)
            {
                if (umap.count(j) > 0)
                    continue;
                arr.push_back(j);
                umap[j] = 1;
            }
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < q; i++)
        {
            long long k;
            cin >> k;

            cout << ((k - 1 < arr.size()) ? arr[k - 1] : -1) << endl;
        }
    }
    return 0;
}
*/