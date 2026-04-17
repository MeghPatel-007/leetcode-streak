#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int reverse(int n){
//         long long rev = 0;
//         while(n!=0){
//             rev = 10*rev + n%10;
//             n/=10;
//         }
//         return int(rev);
//     }
//     unordered_map<int,vector<int>>m;
//     int minMirrorPairDistance(vector<int>& nums) {
//         int mini = INT_MAX;
//         int n = nums.size();
//         for(int i=0;i<nums.size();i++){
//             m[nums[i]].push_back(i);
//         }
//         for(int i=0;i<n;i++){
//             int rev_num = reverse(nums[i]);
//             if(const auto it = m.find(rev_num);it != m.end()){
//                 vector<int> rev_idx = it->second;
//                 for(auto r:rev_idx){
//                     if(mini==1)return 1;
//                     if(i>=r)continue;
//                     mini = min(mini,abs(i-r));
//                 }
//             }
//         }
//         return mini==INT_MAX ? -1 : mini;
//     }
// };

class Solution {
    int reverseNum(int num){
        int res = 0;
        while(num > 0){
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        int res = INT_MAX;
        for(int i = n - 1;i >= 0;i--){
            int reversed = reverseNum(nums[i]);
            if(map.count(reversed)){
                res = min(res,map[reversed] - i);
            }
            map[nums[i]] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};
