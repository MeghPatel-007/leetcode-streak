#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mx(n);
        vector<int> prefixGcd(n);
        int maxi = nums[0];
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
            mx[i] = maxi;
            prefixGcd[i] = __gcd(mx[i], nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0;
        int j = n - 1;
        long long res = 0;
        while (i < j)
        {
            res += __gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return res;
    }
};
