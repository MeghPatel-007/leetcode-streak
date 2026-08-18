#include <bits/stdc++.h>
using namespace std;

// * tc => O(n)
class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        vector<int> v(51, 0);
        int n = nums.size();
        if (n == k)
        {
            return *max_element(nums.begin(), nums.end());
        }
        for (int x : nums)
        {
            v[x]++;
        }
        if (k == 1)
        {
            for (int i = 50; i >= 0; i--)
            {
                if (v[i] == 1)
                    return i;
            }
            return -1;
        }
        int res = -1;
        if (v[nums[0]] == 1)
        {
            res = max(res, nums[0]);
        }
        if (v[nums.back()] == 1)
        {
            res = max(res, nums.back());
        }
        return res;
    }
};
