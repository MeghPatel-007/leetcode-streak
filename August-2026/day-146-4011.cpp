#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countRatioSubarrays(vector<int> &nums, int a, int b)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int even = 0;
            int odd = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % 2 == 0)
                {
                    even++;
                }
                else
                    odd++;
                if (1LL * even * b <= 1LL * odd * a)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
