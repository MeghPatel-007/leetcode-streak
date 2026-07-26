#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>> &series1, vector<vector<int>> &series2)
    {
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        int n1 = series1.size();
        int n2 = series2.size();
        while (i < n1 && j < n2)
        {
            if (series1[i][0] < series2[j][0])
            {
                ans.push_back({series1[i][0], series1[i][1] + series2[j][1]});
                i++;
            }
            else if (series1[i][0] == series2[j][0])
            {
                ans.push_back({series1[i][0], series1[i][1] + series2[j][1]});
                i++;
                j++;
            }
            else
            {
                ans.push_back({series2[j][0], series1[i][1] + series2[j][1]});
                j++;
            }
        }
        while (i < n1)
        {
            ans.push_back({series1[i][0], series1[i][1]});
            i++;
        }
        while (j < n2)
        {
            ans.push_back({series2[j][0], series2[j][1]});
            j++;
        }
        return ans;
    }
};
