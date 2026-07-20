#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> P;
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({intervals[i][1], intervals[i][0]});
        }
        int lastInterval = INT_MIN;
        int cnt = 0;
        while (!pq.empty())
        {
            P interval = pq.top();
            pq.pop();
            if (interval.second >= lastInterval)
            {
                cnt++;
                lastInterval = interval.first;
            }
        }
        return n - cnt;
    }
};
