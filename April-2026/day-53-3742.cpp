#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        dp[0][0][0] = 0;

        auto getCost = [&](int val)
        {
            return val == 0 ? 0 : 1;
        };

        auto getScore = [&](int val)
        {
            return val;
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int c = 0; c <= k; c++)
                {
                    if (dp[i][j][c] == -1)
                        continue;

                    if (i + 1 < m)
                    {
                        int nc = c + getCost(grid[i + 1][j]);
                        if (nc <= k)
                        {
                            dp[i + 1][j][nc] = max(
                                dp[i + 1][j][nc],
                                dp[i][j][c] + getScore(grid[i + 1][j]));
                        }
                    }

                    if (j + 1 < n)
                    {
                        int nc = c + getCost(grid[i][j + 1]);
                        if (nc <= k)
                        {
                            dp[i][j + 1][nc] = max(
                                dp[i][j + 1][nc],
                                dp[i][j][c] + getScore(grid[i][j + 1]));
                        }
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++)
        {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }

        return ans;
    }
};
