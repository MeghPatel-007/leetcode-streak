#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        int ans = 0;
        int n = word.length();
        vector<int> wordCnt(26, 0);
        for (auto &w : word)
        {
            wordCnt[w - 'a']++;
        }
        sort(begin(wordCnt), end(wordCnt), greater<int>());
        for (int i = 0; i < 26 && wordCnt[i] > 0; i++)
        {
            ans += (i / 8 + 1) * wordCnt[i];
        }
        return ans;
    }
};
