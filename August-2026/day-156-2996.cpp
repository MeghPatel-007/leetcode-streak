#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int i = 1;
        int sum = nums[0];
        int n = nums.size();
        if (n == 1)
            return nums[0] + 1;
        while (i < n && nums[i] == nums[i - 1] + 1)
        {
            sum += nums[i];
            i++;
        }
        sort(begin(nums) + i, end(nums));
        i--;
        while (i < n)
        {
            if (sum == nums[i])
                sum++;
            i++;
        }
        return sum;
    }
};
