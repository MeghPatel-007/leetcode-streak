#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void recur(int idx, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            recur(idx + 1, nums);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        recur(0, nums);
        return ans;
    }
};
