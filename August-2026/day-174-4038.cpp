#include <bits/stdc++.h>
using namespace std;

// * hash map
class Solution
{
public:
    int countSpecialIntegers(vector<int> &nums)
    {
        int cnt = 0;
        unordered_map<int, int> block;
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int saved = nums[i];
            while (i < n && saved == nums[i])
            {
                i++;
            }
            block[saved]++;
        }
        for (auto it : block)
        {
            if (it.second == 1)
                cnt++;
        }
        return cnt;
    }
};
