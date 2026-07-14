#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // gcd code
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        return gcd(maxi, mini);
    }
};
