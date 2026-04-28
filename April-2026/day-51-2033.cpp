#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> nums;

        for (auto &row : grid)
        {
            for (int val : row)
            {
                nums.push_back(val);
            }
        }

        int rem = nums[0] % x;
        for (int num : nums)
        {
            if (num % x != rem)
                return -1;
        }

        for (int &num : nums)
        {
            num /= x;
        }

        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];

        int ops = 0;
        for (int num : nums)
        {
            ops += abs(num - median);
        }

        return ops;
    }
};
