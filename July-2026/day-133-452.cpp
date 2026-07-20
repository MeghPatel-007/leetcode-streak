#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // max heap using min heap
    typedef pair<int, int> P;
    int findMinArrowShots(vector<vector<int>> &points)
    {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({points[i][1], points[i][0]});
        }
        int lastArrow = pq.top().first;
        int arrow = 1;
        pq.pop();
        while (!pq.empty())
        {
            P currBalloon = pq.top();
            pq.pop();
            if (lastArrow <= currBalloon.first && lastArrow >= currBalloon.second)
            {
            }
            else
            {
                arrow++;
                lastArrow = currBalloon.first;
            }
        }
        return arrow;
    }
};
