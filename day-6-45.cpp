#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int farthest = 0, jump = 0, end = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);
            if (i == end)
            {
                jump++;
                end = farthest;
            }
        }
        return jump;
    }
};

// there is some hints from the past questions