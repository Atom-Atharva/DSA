// https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <vector>

// No Extra Space
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result_array(n, 1);

        // Store Each Left Product
        int product = 1;
        for (int i = 0; i < n; i++)
        {
            result_array[i] *= product;
            product *= nums[i];
        }

        // Left hai toh right wale se multiply
        product = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            result_array[i] *= product;
            product *= nums[i];
        }

        return result_array;
    }
};

// Extra Space but O(N) Time Complexity
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int product = 1;

        // Make 2 Arrays (Left Product & Right Product)
        vector<int> leftProduct;
        for (int i = 0; i < nums.size(); i++)
        {
            product *= nums[i];
            leftProduct.push_back(product);
        }

        product = 1;
        vector<int> rightProduct(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            product *= nums[i];
            rightProduct[i] = product;
        }

        // For Each Nums Calculate Left Product * Right Product
        vector<int> output;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                output.push_back(rightProduct[i + 1]);
            }
            else if (i == nums.size() - 1)
            {
                output.push_back(leftProduct[i - 1]);
            }
            else
            {
                output.push_back(leftProduct[i - 1] * rightProduct[i + 1]);
            }
        }

        return output;
    }
};