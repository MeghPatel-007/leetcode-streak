#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // brute force
        // int x=0;
        //     for(int i=0;i<nums.size();i++){
        //         if(nums[i]==target)return i;
        //     }
        //     for(int i=0;i<nums.size();i++){
        //         if(target>nums[i])x=i+1;
        //     }
        // return x;
        // int x=0;
        // for(int i=0;i<nums.size();i++){
        //     if(target>nums[i])x=i+1;
        //     if(target<nums[i])break;
        //     if(target==nums[i])return i;
        // }
        // return x;
        //binary tree
         int low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
        }
};