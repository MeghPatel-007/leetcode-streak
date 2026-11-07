#include <bits/stdc++.h>
using namespace std;

// * hash map,unordered_set
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }
        int longest = 0;
        for (auto it : s)
        {
            if (s.find(it - 1) == s.end())
            {
                int cnt = 1;
                int x = it;
                while (s.find(x + 1) != s.end())
                {
                    cnt++;
                    x++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
