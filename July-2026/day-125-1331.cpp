#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> temp(n);
        temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> ranks;
        int r = 1;
        for (int i = 0; i < n; i++)
        {
            if (ranks.find(temp[i]) == ranks.end())
            {
                ranks[temp[i]] = r;
                r++;
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = ranks[arr[i]];
        }
        return ans;
    }
};
