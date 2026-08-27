#include <bits/stdc++.h>
using namespace std;

// * hash map,pair,string
class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<char, int>> m(256);
        for (char ch : s)
        {
            m[ch - '\0'] = {ch, ++m[ch - '\0'].second};
        }
        string res = "";
        sort(begin(m), end(m), [](const auto &a, const auto &b)
             { return a.second > b.second; });
        for (int i = 0; i < 256; i++)
        {
            while (m[i].second != 0)
            {
                res += m[i].first;
                --m[i].second;
            }
        }
        return res;
    }
};
