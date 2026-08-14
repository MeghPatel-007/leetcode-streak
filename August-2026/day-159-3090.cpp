#include <bits/stdc++.h>
using namespace std;

// * sliding Window
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        vector<int> v(26, 0);
        int n = s.size();
        int i = 0;
        int j = 0;
        int mx = 0;
        while (j < n)
        {
            v[s[j] - 'a']++;
            while (v[s[j] - 'a'] > 2)
            {
                v[s[i] - 'a']--;
                i++;
            }
            j++;
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};
