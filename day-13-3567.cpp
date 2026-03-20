#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mini_ab_diff(vector<int> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() <= 1) return 0;
    int min_val = INT_MAX;
    for (int i = 1; i < v.size(); i++) {
        min_val = min(min_val, v[i] - v[i - 1]);
    }
    return min_val;
}
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int m_ans = m-k+1;
        int n_ans = n-k+1;
        vector<vector<int>> ans(m_ans,vector<int>(n_ans,0));
        vector<int> res;
        int space_c = n-k;
        int space_r = m-k;
        for(int x=0;x<=space_r;x++){
            for(int y=0;y<=space_c;y++){
                vector<int> k_grid;
                for(int i=x;i<k+x;i++){
                    for(int j=y;j<k+y;j++){
                        k_grid.push_back(grid[i][j]);
                    }
                }
                res.push_back(mini_ab_diff(k_grid));
            }
        } 
        int inc = 0;
        for(int i=0;i<m_ans;i++){
            for(int j=0;j<n_ans;j++){
                ans[i][j]=res[inc];
                inc++;
            }
        }
        return ans;
    }
};