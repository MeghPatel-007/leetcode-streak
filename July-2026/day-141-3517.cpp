#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int s_len = s.length();
        int p_len = s_len / 2;

        sort(s.begin(), s.begin() + p_len);

        for (int i = 0; i < p_len; i++)
        {
            s[s_len - 1 - i] = s[i];
        }

        return s;
    }
};
