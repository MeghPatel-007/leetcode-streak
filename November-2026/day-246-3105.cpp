#include <bits/stdc++.h>
using namespace std;

// * array
class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int longest = 1;
        int n = nums.size();
        if (n == 1)
            return 1;
        int inc = 1;
        int dec = 1;
        for (int i = 1; i < n; i++)
        {
            inc = nums[i] < nums[i - 1] ? inc + 1 : 1;
            dec = nums[i] > nums[i - 1] ? dec + 1 : 1;
            longest = max({inc, dec, longest});
        }
        return longest;
    }
};
