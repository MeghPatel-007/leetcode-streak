#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int t[23][23];
    int solve(int i, int j, vector<int> &nums)
    {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];
        if (t[i][j] != -1)
        {
            return t[i][j];
        }
        int take_i = nums[i] + min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));
        int take_j = nums[j] + min(solve(i + 1, j - 1, nums), solve(i, j - 2, nums));
        return t[i][j] = max(take_i, take_j);
    }
    bool predictTheWinner(vector<int> &nums)
    {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        int p1 = solve(0, n - 1, nums);
        int total = accumulate(nums.begin(), nums.end(), 0);
        int p2 = total - p1;
        return (p1 >= p2) ? true : false;
    }
};
