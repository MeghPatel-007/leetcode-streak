#include <bits/stdc++.h>
using namespace std;

// * subsequence , recursion

// mine soln
// class Solution {
// public:
//     vector<vector<int>>ans;
//     void solve(int idx,int sum,int& target,vector<int> selected,vector<int>& candidates){
//         if(idx == candidates.size()){
//             if(sum == target){
//                 ans.push_back(selected);
//             }
//             return;
//         }
//         selected.push_back(candidates[idx]);
//         sum += candidates[idx];
//         if(target >= sum){
//             solve(idx,sum,target,selected,candidates);
//         }
//         selected.pop_back();
//         sum -= candidates[idx];
//         solve(idx+1,sum,target,selected,candidates);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         solve(0,0,target,{},candidates);
//         return ans;
//     }
// };

// striver soln
class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int idx, int target, vector<int> selected, vector<int> &candidates)
    {
        if (idx == candidates.size())
        {
            if (!target)
            {
                ans.push_back(selected);
            }
            return;
        }
        if (target >= candidates[idx])
        {
            selected.push_back(candidates[idx]);
            solve(idx, target - candidates[idx], selected, candidates);
            selected.pop_back();
        }
        solve(idx + 1, target, selected, candidates);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end(), greater<int>());
        solve(0, target, {}, candidates);
        return ans;
    }
};
