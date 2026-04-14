#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        vector<long long> fac;
        for (int i = 0; i < factory.size(); i++)
        {
            while (factory[i][1] != 0)
            {
                fac.push_back(factory[i][0]);
                factory[i][1]--;
            }
        }
        sort(fac.begin(), fac.end());
        int n = robot.size();
        int m = fac.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e16));

        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                long long skip = dp[i][j - 1];
                long long take = abs(robot[i - 1] - fac[j - 1]) + dp[i - 1][j - 1];
                dp[i][j] = min(skip, take);
            }
        }
        return dp[n][m];
    }
};