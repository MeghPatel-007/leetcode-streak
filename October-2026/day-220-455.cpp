#include <bits/stdc++.h>
using namespace std;

// * greedy,2 pointer
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(begin(s), end(s));
        sort(begin(g), end(g));
        int i = 0, j = 0, cnt = 0;
        while (i < g.size() && j < s.size())
        {
            if (s[j] >= g[i])
            {
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};
