#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool checker(vector<vector<int>> grid){
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     long long sum = 0;
    //     for(auto i:grid){
    //         for(auto j:i){
    //             sum+=j;
    //         }
    //     }
    //     long long prefix=0;
    //     for(int i=0;i<m-1;i++){
    //         for(int j=0;j<n;j++){
    //             prefix+=grid[i][j];
    //         }
    //         if(prefix==sum-prefix)return true;
    //     }
    //     return false;
    // }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // int m = grid.size();
        // int n = grid[0].size();
        // if(checker(grid)){
        //     return true;
        // }else{
        //     vector<vector<int>>grid_2(n,vector<int>(m,0));
        //     //twist if the original does not work
        //     for(int i=0;i<m;i++){
        //         for(int j=0;j<n;j++){
        //             grid_2[j][i]=grid[i][j];
        //         }
        //     }
        //     if(checker(grid_2)){
        //         return true;
        //     }
        //     return false;
        // }
        // return false;

        //optimized
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        for(auto i:grid){
            for(auto j:i){
                total+=j;
            }
        }
        long long prefix = 0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                prefix+=grid[i][j];
            }
            if(prefix==total-prefix)return true;
        }
        vector<long long>col(n,0);
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                col[j]+=grid[i][j];
            }
        }
        prefix=0;
        for(int i=0;i<n-1;i++){
            prefix+=col[i];
            if(prefix==total-prefix)return true;
        }
        return false;
    }
};