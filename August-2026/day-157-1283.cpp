#include <bits/stdc++.h>
using namespace std;

// * binary search on answers tc => O(nlogn)
class Solution
{
public:
    int sum_divisor(vector<int> &nums, int divisor)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += ceil((double)nums[i] / divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        if (nums.size() > threshold)
            return -1;
        int l = 1;
        int r = *max_element(begin(nums), end(nums));
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (sum_divisor(nums, mid) <= threshold)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
