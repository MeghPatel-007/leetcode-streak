#include <bits/stdc++.h>
using namespace std;

// * perfixsum
class Solution
{
public:
    int countGoodRotations(vector<int> &nums)
    {
        int n = nums.size();
        int firstMid = n / 2;
        vector<long long> sum(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++)
        {
            sum[i + 1] = nums[i % n] + sum[i];
        }
        int score = 0;
        for (int i = 0; i < n; i++)
        {
            long long firstSum = sum[firstMid + i] - sum[i];
            long long lastSum = sum[n + i] - sum[firstMid + i];
            if (firstSum > lastSum)
                score++;
        }
        return score;
    }
};
