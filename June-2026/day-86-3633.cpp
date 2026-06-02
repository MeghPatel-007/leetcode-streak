#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime, vector<int> &waterDuration)
    {
        int i = 0;
        int j = 0;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int mini = INT_MAX;
        int bestland = INT_MAX;
        int bestwater = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            bestland =
                min(bestland,
                    landStartTime[i] + landDuration[i]);
        }

        for (int j = 0; j < m; j++)
        {
            bestwater =
                min(bestwater,
                    waterStartTime[j] + waterDuration[j]);
        }

        for (int j = 0; j < m; j++)
        {
            mini = min(mini, max(bestland, waterStartTime[j]) + waterDuration[j]);
        }
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, max(bestwater, landStartTime[i]) + landDuration[i]);
        }
        return mini;
    }
};
