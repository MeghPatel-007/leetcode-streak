#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dp;
    int solve(int i, vector<int> &nums, int target)
    {
        if (i == nums.size() - 1)
            return 0;
        if (dp[i] != -2)
            return dp[i];
        int ans = -1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            int diff = nums[j] - nums[i];
            if (-target <= diff && diff <= target)
            {
                int candidate = solve(j, nums, target);
                if (candidate != -1)
                {
                    ans = max(ans, 1 + candidate);
                }
            }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int> &nums, int target)
    {
        dp.resize(nums.size(), -2);
        return solve(0, nums, target);
    }
};
