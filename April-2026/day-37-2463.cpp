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

// //learn from yt
// class Solution
// {
//     #define MAX 10000000000000LL
//     using 11 = long long;

//     11 mincost(vector<int> &robot, int robo_pos, vector<int> &factories, int fact_pos, vector<vector<11>> &mem)
//     {
//         if (robo_pos < 0)
//             return 0; // If all robots are repaired
//         if (fact_pos < 0)
//             return MAX; // If some robots are left but factories are over
//         if (mem[robo_pos][fact_pos] != -1)
//             return mem[robo_pos][fact_pos];

//         11 include = abs(robot[robo_pos] - factories[fact_pos]) + mincost(robot, robo_pos - 1, factories, fact_pos - 1, mem);

//         11 exclude = mincost(robot, robo_pos, factories, fact_pos - 1, mem);

//         return mem[robo_pos][fact_pos] = min(include, exclude);
//     }

// public:
//     long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
//     {
//         sort(robot.begin(), robot.end());
//         sort(factory.begin(), factory.end());

//         // Convert multi-instance factory to single instance
//         vector<int> factories;
//         for (int i = 0; i < factory.size(); ++i)
//         {
//             int pos = factory[i][0];
//             int count = factory[i][1];
//             for (int j = 0; j < count; ++j)
//                 factories.push_back(pos);

//             vector<vector<11>> mem(robot.size(), vector<11>(factories.size(), -1));
//             return mincost(robot, robot.size() - 1, factories, factories.size() - 1, mem);
//         }
//     }
// }