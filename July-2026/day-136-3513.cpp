#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        if(n==1)return 1;
        if(n==2)return 2;
        while(i<=n)i=i<<1;
        return i;
    }
};
