#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        unordered_set<char> m(word.begin(), word.end());
        int output = 0;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (m.count(ch) && m.count(toupper(ch)))
                output++;
        }
        return output;
    }
};
