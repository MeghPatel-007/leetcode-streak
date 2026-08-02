#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    long long maxPairStrength(vector<int> &nums)
    {
        long long mx = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long gcd = __gcd(nums[i], nums[j]) % MOD;
                long long mul = (nums[i] * 1LL) * (nums[j] * 1LL);
                long long ans = mul / (gcd * gcd);
                mx = max(mx, ans);
            }
        }
        return mx;
    }
};
