#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int n = word.length();
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            char ch = word[i];
            if (isupper(ch) && upper[ch - 'A'] == -1)
            {
                upper[ch - 'A'] = i;
            }
            if (islower(ch))
            {
                lower[ch - 'a'] = i;
            }
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (lower[ch - 'a'] != -1 && upper[ch - 'a'] != -1 && lower[ch - 'a'] < upper[ch - 'a'])
            {
                ans++;
            }
        }
        return ans;
    }
};
