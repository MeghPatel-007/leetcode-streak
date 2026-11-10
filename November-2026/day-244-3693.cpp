#include <bits/stdc++.h>
using namespace std;

// * dp , bottom up 
class Solution
{
public:
    int climbStairs(int n, vector<int> &costs)
    {
        vector<long long> t(n + 1, 1e18);
        t[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i - 1 >= 0)
            {
                t[i] = min(t[i], costs[i - 1] + 1 + t[i - 1]);
            }
            if (i - 2 >= 0)
            {
                t[i] = min(t[i], costs[i - 1] + 4 + t[i - 2]);
            }
            if (i - 3 >= 0)
            {
                t[i] = min(t[i], costs[i - 1] + 9 + t[i - 3]);
            }
        }
        return t[n];
    }
};
