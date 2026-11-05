#include <bits/stdc++.h>
using namespace std;

// * bit manipulation,shift operator
class Solution
{
public:
    vector<string> powerSet(string &s)
    {
        int n = s.length();
        int total = 1 << n;
        vector<string> res;
        for (int mask = 0; mask < total; mask++)
        {
            string curr = "";

            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    curr += s[i];
                }
            }

            res.push_back(curr);
        }

        return res;
    }
};
