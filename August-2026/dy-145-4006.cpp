#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countValidPrefixes(string s)
    {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt = 0;
        for (auto &str : s)
        {
            if (str == '0')
                cnt0++;
            else
                cnt1++;
            if (abs(cnt0 - cnt1) < 2)
                cnt++;
        }
        return cnt;
    }
};
