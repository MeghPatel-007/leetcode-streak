#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());

        unordered_set<int> present(nums.begin(), nums.end());

        vector<int> result;
        for (int num = min_val; num <= max_val; ++num)
        {
            if (present.find(num) == present.end())
            {
                result.push_back(num);
            }
        }

        return result;
    }
};
