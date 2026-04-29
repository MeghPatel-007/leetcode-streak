#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long maximumScore(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<long long>> pre(n, vector<long long>(n + 1, 0));
        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                pre[j][i + 1] = pre[j][i] + grid[i][j];
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

        for (int h = 0; h <= n; ++h)
        {
            dp[h][0] = 0;
            dp[h][1] = 0;
        }

        for (int j = 1; j < n; ++j)
        {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(2, 0));

            for (int c = 0; c <= n; ++c)
            {
                for (int p = 0; p <= n; ++p)
                {

                    long long gain_inc = (c > p) ? (pre[j - 1][c] - pre[j - 1][p]) : 0;

                    next_dp[c][0] = max(next_dp[c][0], dp[p][0] + gain_inc);
                    next_dp[c][0] = max(next_dp[c][0], dp[p][1]);

                    long long gain_dec = (p > c) ? (pre[j][p] - pre[j][c]) : 0;

                    next_dp[c][1] = max(next_dp[c][1], dp[p][1] + gain_dec);
                    next_dp[c][1] = max(next_dp[c][1], dp[p][0] + gain_dec);
                }
            }
            dp = next_dp;
        }

        long long max_score = 0;
        for (int h = 0; h <= n; ++h)
        {
            max_score = max({max_score, dp[h][0], dp[h][1]});
        }
        return max_score;
    }
};
