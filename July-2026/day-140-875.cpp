#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long eating(int k, vector<int> &piles)
    {
        long long totalhrs = 0;
        for (auto &pile : piles)
        {
            totalhrs += (pile + k - 1LL) / k;
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int max = *max_element(piles.begin(), piles.end());
        int l = 1;
        int r = max;
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (eating(mid, piles) <= h)
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
