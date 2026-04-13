#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // rotation formula by 90 deg
    void rotate(vector<vector<int>>& matrix) {
        //transpose
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix.size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse each rows
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};