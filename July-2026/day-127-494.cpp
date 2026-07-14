#include <bits/stdc++.h>
using namespace std;

// no memoization => tc = 2^n
//                   sc = n

// with => tc =
class Solution
{
public:
    int s;
    int solve(vector<int> &nums, int i, int sum, int target, vector<vector<int>> &t)
    {
        if (i == nums.size())
        {
            if (sum == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        if (t[i][sum + s] != -1)
        {
            return t[i][sum + s];
        }

        int add = solve(nums, i + 1, sum + nums[i], target, t);
        int sub = solve(nums, i + 1, sum - nums[i], target, t);

        return t[i][sum + s] = add + sub;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        // int sum = 0;
        // for(auto& n : nums)sum+=n;
        s = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> t(n + 1, vector<int>(2 * s + 1, -1));
        return solve(nums, 0, 0, target, t);
    }
};
