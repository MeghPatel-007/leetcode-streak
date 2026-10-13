#include<bits/stdc++.h>
using namespace std;

// * array
class Solution
{
public:
    vector<int> maxProductPair(vector<int> &nums, int target)
    {
        int max_i = 0;
        int max_j = 0;
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[i] > nums[j] && nums[i] + nums[j] == target)
                {
                    if (nums[i] * nums[j] > maxi)
                    {
                        maxi = nums[i] * nums[j];
                        max_i = i;
                        max_j = j;
                    }
                }
            }
        }
        if (maxi == INT_MIN)
        {
            return {-1, -1};
        }
        else
        {
            return {max_i, max_j};
        }
    }
};
