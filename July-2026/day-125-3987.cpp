#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long MOD = 1e9+7;
        long long n = nums.size();
        long long fk = k;
        long long cnt = 0;
        long long x = 1;
        for(int i=0;i<n;i++){
            if(fk < nums[i]){
                long long  m  = (1LL * nums[i] - fk + k - 1)/k;
                //term1
                long long term1 = (x%MOD)*(m%MOD)%MOD;
                //term2
                long long term2;
                if(m%2==0) term2 = ((m/2)%MOD) * ((m-1)%MOD)%MOD;
                else term2 = ((m)%MOD) * (((m-1)/2)%MOD)%MOD;
                cnt = (cnt + term1 + term2)%MOD;
                x = (x+m)%MOD;
                fk += m*k;
            }
            fk -= nums[i];
        }
        return cnt % MOD;
    }
};
