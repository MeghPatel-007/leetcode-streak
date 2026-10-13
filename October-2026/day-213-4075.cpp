#include <bits/stdc++.h>
using namespace std;

// * modular arithmatic , math
class Solution
{
public:
    typedef long long ll;
    int resilientSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int max_len = 1;
        for (int i = 0; i < n; i++)
        {
            ll r = nums[i] % k;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % k != r)
                {
                    break;
                }
                int L = j - i + 1;
                if ((ll)((L - 1) * r) % k == 0)
                {
                    max_len = max(max_len, L);
                }
            }
        }
        return max_len;
    }
};
