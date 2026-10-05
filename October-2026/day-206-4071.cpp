#include <bits/stdc++.h>
using namespace std;

// * precomputation,array
class Solution
{
public:
    int dist(int x, int y)
    {
        return min(10 - abs(x - y), (abs(x - y)));
    }
    int minRotations(int n, string s)
    {
        vector<long long> suf(n + 1, 0);
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] + dist(s[i] - '0', s[i + 1] - '0');

        long long best = LLONG_MAX;
        long long pre = 0;
        int prev = 0;
        int last = s[n - 1] - '0';

        for (int k = 0; k < n; k++)
        {
            best = min(best, pre + dist(prev, last) + suf[k]);
            int cur = s[k] - '0';
            pre += dist(prev, cur);
            prev = cur;
        }
        best = min(best, pre);

        return (int)best;
    }
};
