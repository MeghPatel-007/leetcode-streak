#include <bits/stdc++.h>
using namespace std;

// * hash map
class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        unordered_set<int> num(nums.begin(), nums.end());
        int multiple = k;
        int i = 1;
        while (multiple <= 100)
        {
            if (num.find(multiple) != num.end())
            {
                multiple = k * ++i;
            }
            else
                break;
        }
        return multiple;
    }
};
