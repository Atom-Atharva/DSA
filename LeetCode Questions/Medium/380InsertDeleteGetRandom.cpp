// https://leetcode.com/problems/insert-delete-getrandom-o1/?envType=daily-question&envId=2024-01-16

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class RandomizedSet
{
    vector<int> arr;
    unordered_map<int, int> umap;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (umap.count(val) != 0)
        {
            return false;
        }
        arr.push_back(val);
        umap[val] = arr.size() - 1;

        return true;
    }

    bool remove(int val)
    {
        if (umap.count(val) == 0)
        {
            return false;
        }

        // Swap Last and Removing Element
        int position = umap[val];
        int lastPos = arr.size() - 1;

        arr[position] = arr[lastPos];
        umap[arr[lastPos]] = position;
        arr[lastPos] = val;

        // Remove Last Element
        arr.pop_back();
        umap.erase(val);

        return true;
    }

    int getRandom()
    {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */