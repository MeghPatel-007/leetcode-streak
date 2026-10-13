#include<bits/stdc++.h>
using namespace std;

// * math,optimize,modular arithmatic
class Solution {
public:
    typedef long long ll;
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 1;
        int i =0;
        while(i<n){
            ll r = nums[i] % k;
            int j = i;
            while(j<n && nums[j]%k == r){
                j++;
            }
                int seg_len = j-i;
            if(r==0){
                max_len = max(max_len,seg_len);
            }else{
                ll g = gcd(r,k);
                ll M = k/g;
                if(seg_len >= 1){
                    ll L = 1+((seg_len-1)/M)*M;
                    max_len = max(max_len,(int)L);
                }
            }
            i=j;
        }
        return max_len;
    }
};
