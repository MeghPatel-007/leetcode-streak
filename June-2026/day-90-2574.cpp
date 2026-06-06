#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int suml = 0;
        int sumr = 0;
        for(int n:nums){
            sumr += n;
        }
        for(int i=0;i<n;i++){
            suml += nums[i];
            ans[i] = abs(sumr - suml);
            sumr -= nums[i];
        }
        return ans;
    }
};
