#include <bits/stdc++.h>
using namespace std;

// * Binary search on answer max(min)
class Solution
{
public:
    bool largestSumSplit(vector<int> &nums, int &n, int expK, int sum)
    {
        int k = 1;
        int i = 0;
        int splitSum = 0;
        while (i < n)
        {
            if (splitSum + nums[i] > sum)
            {
                splitSum = 0;
                k++;
            }
            splitSum += nums[i];
            i++;
        }
        return k > expK;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int l = *max_element(begin(nums), end(nums));
        int r = accumulate(begin(nums), end(nums), 0);
        int n = nums.size();
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (largestSumSplit(nums, n, k, mid))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};
