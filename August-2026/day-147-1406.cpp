#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        vector<string> s = {"Alice", "Bob", "Tie"};
        int n = stoneValue.size();
        vector<int> t(n + 1);
        for (int i = n - 1; i >= 0; i--)
        {
            t[i] = stoneValue[i] - t[i + 1];
            if (i + 1 < n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i + 1] - t[i + 2]);
            if (i + 2 < n)
                t[i] = max(t[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - t[i + 3]);
        }
        if (t[0] > 0)
            return s[0];
        else if (t[0] < 0)
            return s[1];
        else
            return s[2];
    }
};
