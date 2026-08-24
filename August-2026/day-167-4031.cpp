#include <bits/stdc++.h>
using namespace std;

// * sliding window
class Solution
{
public:
    vector<vector<int>> findDisappearedNumbers(vector<int> &nums, int lower, int upper)
    {
        int low = lower;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < low)
                continue;
            if (nums[i] > upper)
                break;
            int checkpoint = nums[i] - 1;
            if (low <= checkpoint)
                ans.push_back({low, checkpoint});
            low = nums[i] + 1;
        }
        if (low <= upper)
            ans.push_back({low, upper});
        return ans;
    }
};
