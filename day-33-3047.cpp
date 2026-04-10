#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<int, vector<int>> m;
    int val, mini = INT_MAX;
    int minimumDistance(vector<int> &nums)
    {
        if (nums.size() < 3)
            return -1;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }
        for (auto v : m)
        {
            if (v.second.size() == 3)
            {
                val = abs(v.second[0] - v.second[1]) + abs(v.second[1] - v.second[2]) + abs(v.second[2] - v.second[0]);
                mini = min(val, mini);
            }
        }
        if (mini == INT_MAX)
            return -1;
        return mini;
    }
};