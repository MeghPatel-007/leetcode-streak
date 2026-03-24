#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>flat;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                flat.push_back(grid[i][j]%12345);
            }
        }
        int size = flat.size();
        vector<int>prefix(size,1),suffix(size,1);
        // alternative of matrix multiplication is by using the prefix and suffix method
        // prefix is the array of mulitplication before the i
        // suffix is the array of mulitplication after the i
        //by mulitplying both the array gives the matrix mulitplication
        for(int i=1;i<size;i++){
            prefix[i] = (prefix[i-1]*flat[i-1])%12345;
        }
        for(int i=size-2;i>=0;i--){
            suffix[i] = (suffix[i+1]*flat[i+1])%12345;
        }
        vector<vector<int>>res(m,vector<int>(n,1));
        for(int i=0;i<size;i++){
            int val = (prefix[i]*suffix[i])%12345;
            res[i/n][i%n] = val; //it is used to convert 1d to 2d matrix
        }
        return res;
    }
};