#include <bits/stdc++.h>
using namespace std;

// * subsequences
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int idx, int n, int k, vector<int> selected)
    {
        if (selected.size() == k)
        {
            if (n == 0)
            {
                ans.push_back(selected);
            }
            return;
        }
        if (idx > 9 || n < idx)
            return;
        selected.push_back(idx);
        solve(idx + 1, n - idx, k, selected);
        selected.pop_back();
        solve(idx + 1, n, k, selected);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        solve(1, n, k, {});
        return ans;
    }
};
