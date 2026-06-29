#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        // while(y != n){
        //     ans.push_back(nums[y]);
        //     y++;
        // }
        // int x = 0;
        // while(x != breakpoint){
        //     ans.push_back(nums[x]);
        //     x++;
        // }
        // nums = ans;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }
};
