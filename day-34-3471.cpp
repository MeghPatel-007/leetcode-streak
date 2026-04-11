#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    using int2=array<int, 2>;
    static int minimumDistance(vector<int>& nums) {
        const int n=nums.size(), M=*max_element(nums.begin(), nums.end());
        const int2 none={-1, -1};
        vector<int2> pos(M+1, none);
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            const int x=nums[i];
            if (pos[x][1]!=-1){
                ans=min(ans, (i-pos[x][1])<<1);
            }
            pos[x][1]=exchange(pos[x][0], i);
        }
        return ans==INT_MAX?-1:ans;
    }
    // map<int,vector<int>>m;
    // int minimumDistance(vector<int>& nums) {
    //     int n = nums.size(),mini=INT_MAX;
    //     for(int i=0;i<nums.size();i++){
    //         m[nums[i]].push_back(i);
    //     }
    //     for(auto [key,val]:m){
    //         if(val.size()<=2)continue;
    //         int mini_val = INT_MAX;
    //         for(int i=0;i<val.size()-2;i++){
    //             int p=val[i],r=val[i+2];
    //             mini_val = min(mini_val,r-p);
    //             if(r-p == mini_val){
    //                 mini = min(2*(r-p),mini);
    //             }
    //         }
    //     }
    //     return mini==INT_MAX?-1:mini;
// }
};