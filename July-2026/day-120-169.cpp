#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        int el = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el)
                cnt++;
            else if (cnt == 0)
            {
                cnt = 1;
                el = nums[i];
            }
            else
            {
                cnt--;
            }
        }
        int cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (el == nums[i])
                cnt2++;
        }
        if (cnt2 > n / 2)
            return el;
        return -1;
    }
};
