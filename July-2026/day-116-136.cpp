#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // unordered_map<int,int> m;
        // int ans = 0;
        // for(int n:nums){
        //     m[n]++;
        // }
        // for(auto& [k,v]:m){
        //     if(v == 1)ans=k;
        // }
        // return ans;
        int ans = 0;
        for (int n : nums)
        {
            ans = ans ^ n;
        }
        return ans;
    }
};
