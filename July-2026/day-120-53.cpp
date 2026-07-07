#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // kadane's algo
        int sum = 0;
        int maxi = INT_MIN;
        for (int n : nums)
        {
            sum += n;
            maxi = max(maxi, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};
