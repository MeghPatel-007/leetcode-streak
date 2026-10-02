#include <bits/stdc++.h>
using namespace std;

// * subsequence,subset,recursion
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int idx, vector<int> selected, vector<int> &nums)
    {
        ans.push_back(selected);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i != idx && nums[i - 1] == nums[i])
                continue;
            selected.push_back(nums[i]);
            solve(i + 1, selected, nums);
            selected.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        solve(0, {}, nums);
        return ans;
    }
};
