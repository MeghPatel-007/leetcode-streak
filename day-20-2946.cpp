#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        //mine-brute force
        int m = mat.size();
        int n = mat[0].size();
        k = k % n; //reduce unneccesary rotation
            for(int i=0;i<m;i++){   
                for(int j=0;j<n;j++){
                    int expected;
                    if(i % 2 == 0) {
                        expected = mat[i][(j + k) % n]; //shifting logic j+how many shifts to the left and if the value is out of bounds therefore %n
                    } else {
                        expected = mat[i][(j - k + n) % n]; //shifting logic j+how many shifts to the right and +n for non negative numbers and %n if value out of bounds
                    }
                    if(mat[i][j] != expected) {
                        return false;
                    }
                }
            }
    return true;
    }
};