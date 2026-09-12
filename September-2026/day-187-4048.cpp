#include <bits/stdc++.h>
using namespace std;

// * hashmap
class Solution
{
public:
    int countSpecialIntegers(vector<int> &nums)
    {
        unordered_map<int, vector<int>> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            m[nums[i]].push_baack(i);
        }
        int distinct = 0;
        for (auto &it : m)
        {
            vector<int> v = it.second;
            if (v.size() == 3 && (v[1] - v[0] == v[2] - v[1]))
            {
                distinct++;
            }
        }
        return distinct;
    }
};
