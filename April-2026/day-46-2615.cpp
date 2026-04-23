#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    vector<long long>answer(n,0);
    unordered_map<int,vector<int>>m;
    for(int i=0;i<n;i++){
        m[nums[i]].push_back(i);
    }
    for(auto it:m){
        vector<int>&v = it.second;
        int k = v.size();
        vector<long long> pref(k+1,0);
        for(int i=0;i<k;i++){
            pref[i+1] = pref[i] + v[i];
        }
        for(int i=0;i<k;i++){
            long long right = (pref[k]-pref[i+1])-(long long)v[i]*(k-i-1); //formula -> right
            long long left = (long long)v[i]*i-pref[i]; //formula -> left
            answer[v[i]]+=left+right;
        }
    }
    return answer;
    }
};
