#include <bits/stdc++.h>
using namespace std;

// * Hashmap
class Solution
{
public:
    typedef long long ll;
    int countSpecialIntegers(vector<int> &nums)
    {
        unordered_map<int, vector<int>> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            m[nums[i]].push_back(i);
        }
        int distinct = 0;
        for (auto &it : m)
        {
            vector<int> v = it.second;
            if (v.size() >= 3)
            {
                int m = v.size();
                bool isEqual = true;
                for (int i = 2; i < m; i++)
                {
                    if (v[i] - v[i - 1] != v[i - 1] - v[i - 2])
                    {
                        isEqual = false;
                        break;
                    }
                }
                if (isEqual)
                    distinct++;
            }
        }
        return distinct;
    }
};
