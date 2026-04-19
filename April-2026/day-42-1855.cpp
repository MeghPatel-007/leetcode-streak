#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        //brute force O(n^2)
        // int maxi = 0;
        //     for(int i=0;i<nums1.size();i++){
        //         for(int j=0;j<nums2.size();j++){
        //             if(i<=j && nums1[i] <= nums2[j]){
        //                 maxi = max(maxi,j-i);
        //             }
        //         }
        //     }
        // return maxi;
        int maxi = 0;
        int i=0,j=0;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                maxi = max(maxi,j-i);
                j++;
            }else{
                i++;
                if(i>j)j=i;
            }
        }
        return maxi;
    }
};
