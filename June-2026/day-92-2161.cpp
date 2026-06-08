#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> ans;
        int count = 0;
        for (auto n : nums)
        {
            if (n == pivot)
            {
                ++count;
            }
            if (n < pivot)
            {
                ans.push_back(n);
            }
        }
        for (int i = 0; i < count; i++)
        {
            ans.push_back(pivot);
        }
        for (auto n : nums)
        {
            if (n > pivot)
            {
                ans.push_back(n);
            }
        }
        return ans;
    }
};
