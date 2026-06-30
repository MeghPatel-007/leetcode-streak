#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int x = 0;
        int y = 0;
        int n = nums.size();
        while (x < n && y < n)
        {
            if (y <= x)
            {
                y = x + 1;
            }
            else if (nums[x] != 0)
            {
                x++;
            }
            else if (nums[y] == 0)
            {
                y++;
            }
            else
            {
                swap(nums[x], nums[y]);
                x++;
                y++;
            }
        }
    }
};
