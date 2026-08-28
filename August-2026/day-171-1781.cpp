#include <bits/stdc++.h>
using namespace std;

// * hash map,string
class Solution
{
public:
    int beautySum(string s)
    {
        int n = s.length();
        int beauty = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++)
            {
                int mn = INT_MAX;
                int mx = INT_MIN;
                freq[s[j]]++;
                for (auto it : freq)
                {
                    mn = min(it.second, mn);
                    mx = max(it.second, mx);
                }
                beauty += mx - mn;
            }
        }
        return beauty;
    }
};
