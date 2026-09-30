#include <bits/stdc++.h>
using namespace std;

// * subsquence,recursion
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int idx, int target, vector<int> selected, vector<int> &candidates)
    {
        if (target == 0)
        {
            ans.push_back(selected);
            return;
        }
        for (int i = idx; i < candidates.size(); i++)
        {
            if (target < candidates[i])
                break;
            if (i > idx && candidates[i - 1] == candidates[i])
                continue;
            selected.push_back(candidates[i]);
            solve(i + 1, target - candidates[i], selected, candidates);
            selected.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        solve(0, target, {}, candidates);
        return ans;
    }
};
