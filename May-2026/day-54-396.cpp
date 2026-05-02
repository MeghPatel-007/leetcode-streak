#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // O(n^2)
        // int n = nums.size();
        // int clk = 0;
        // long long maxi = 0;
        // for(int i=0;i<n;i++){
        //     int clk2 = clk;
        //     long long  sum = 0;
        //     for(int idx=0;idx<n;idx++){
        //         if(clk2==n&&clk>0)clk2=0;
        //         sum += idx*nums[clk2];
        //         clk2++;
        //     }
        //     maxi = max(maxi,sum);
        //     clk++;
        // }
        // return maxi;
        //O(n)
        int n = nums.size();
        long long sum = 0, F = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }

        long long maxi = F;

        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n - k];
            maxi = max(maxi, F);
        }

        return maxi;
    }
};
