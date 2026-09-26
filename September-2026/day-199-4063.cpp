#include <bits/stdc++.h>
using namespace std;

// * optimization,array
class Solution
{
public:
    typedef long long ll;
    int longestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;
        vector<int> cnt(k, 0);
        for (int i = 0; i < n; i++)
        {
            ll currentSum = 0;
            vector<int> touched;
            for (int j = i; j < n; j++)
            {
                currentSum += nums[j];

                int rx = (int)(((2LL * nums[j]) % k + k) % k);
                if (cnt[rx] == 0)
                    touched.push_back(rx);
                cnt[rx]++;

                int r = (int)((currentSum % k + k) % k);
                if (r == 0 || cnt[r] > 0)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
            for (int r : touched)
                cnt[r] = 0;
        }
        return maxLen;
    }
};
