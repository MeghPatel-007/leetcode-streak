#include <bits/stdc++.h>
using namespace std;

// * power set and recursion , subsequences 
class Solution
{
public:
    // 2^n*n
    vector<vector<int>> ans;
    void solve(int idx, vector<int> selected, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            ans.push_back(selected);
            return;
        }
        selected.push_back(nums[idx]);
        solve(idx + 1, selected, nums);
        selected.pop_back();
        solve(idx + 1, selected, nums);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        solve(0, {}, nums);
        return ans;
    }
};
