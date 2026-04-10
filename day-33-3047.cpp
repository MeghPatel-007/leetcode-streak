#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size(),mini=1e9;

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]){
                        int dist=abs(i-j)+abs(j-k)+abs(k-i);
                        mini=min(mini,dist);
                    }
                }
            }
        }

        return mini==1e9?-1:mini;
    }
};

// class Solution {
// public:
//     map<int,vector<int>>m;
//     int val,mini=INT_MAX;
//     int minimumDistance(vector<int>& nums) {
//         if(nums.size()<3)return -1;
//         for(int i=0;i<nums.size();i++){
//             m[nums[i]].push_back(i);
//         }
//         for(auto v : m){
//             if(v.second.size()>2){
//                 for(int i=0;i<v.second.size();i++){
//                     for(int j=i+1;j<v.second.size();j++){
//                         for(int k=j+1;k<v.second.size();k++){
//                             val = abs(v.second[i]-v.second[j])+abs(v.second[j]-v.second[k])+abs(v.second[k]-v.second[i]);
//                             mini = min(val,mini);
//                         }
//                     }
//                 }
//             }
//         }
//         if(mini==INT_MAX)return -1;
//         return mini;
//     }
// };
