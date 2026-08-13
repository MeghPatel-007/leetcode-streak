#include <bits/stdc++.h>
using namespace std;

// * Binary Search on answer
class Solution
{
public:
    bool capacity_day(int exp_capacity, int exp_days, vector<int> &weights)
    {
        int days = 0;
        int capacity = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            capacity += weights[i];
            if (exp_capacity < capacity)
            {
                capacity = weights[i];
                days++;
            }
        }
        return days < exp_days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int l = *max_element(begin(weights), end(weights));
        int r = accumulate(begin(weights), end(weights), 0);
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (capacity_day(mid, days, weights))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};
