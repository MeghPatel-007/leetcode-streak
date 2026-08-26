#include <bits/stdc++.h>
using namespace std;

// * String,hash map
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> m(26, 0);
        for (char ch : s)
        {
            m[ch - 'a']++;
        }
        for (char ch : t)
        {
            m[ch - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (m[i] != 0)
                return false;
        }
        return true;
    }
};
