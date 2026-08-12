#include <bits/stdc++.h>
using namespace std;

// * sliding window Tc = O(2n)
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int i = 0, j = 0, n = nums.size(), result = 0;
        unordered_map<int, int> m;
        while (j < n)
        {
            m[nums[j]]++;
            while (m[nums[j]] > k)
            {
                m[nums[i]]--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};
