#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        // unordered_set<int>s1;
        // unordered_set<int>s2;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         s1.insert(nums[i]^nums[j]);
        //     }
        // }
        // for(int xorPair : s1){
        //     for(int &num : nums){
        //         s2.insert(num^xorPair);
        //     }
        // }
        // return s2.size();

        // improved
        int max = *max_element(nums.begin(), nums.end());
        int t = 1;
        int n = nums.size();
        if (n == 1)
            return 1;
        while (t <= max)
        {
            t <<= 1;
        }
        vector<int> s1(t, false);
        vector<int> s2(t, false);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                s1[nums[i] ^ nums[j]] = true;
            }
        }
        for (int i = 0; i < t; i++)
        {
            if (s1[i] == true)
            {
                for (auto &num : nums)
                {
                    s2[i ^ num] = true;
                }
            }
        }
        int cnt = 0;
        for (bool s : s2)
        {
            if (s == true)
                cnt++;
        }
        return cnt;
    }
};
