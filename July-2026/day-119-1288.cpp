#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int size = n;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0]; });
        int maxRight = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][1] <= maxRight)
                size--;
            else
                maxRight = intervals[i][1];
        }
        return size;
    }
};
