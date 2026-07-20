#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 2-d => 1-d => 2-d
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int len = n*m;
        vector<int>linearGrid(len);
        k = k % len;
        int last = linearGrid[len-1];
        for(int i=0;i<len;i++){
            linearGrid[(i+k)%len] = grid[i/m][i%m];
        }
        for(int i=0;i<len;i++){
                grid[i/m][i%m] = linearGrid[i];
        }
        return grid;
    }
};
