#include <bits/stdc++.h>
using namespace std;

// * dp
class Solution
{
public:
    // recursion
    int solve(int s1Idx, int s2Idx, string &text1, string &text2, vector<vector<int>> &t)
    {
        if (s1Idx == text1.length() || s2Idx == text2.length())
            return 0;
        if (t[s1Idx][s2Idx] != -1)
            return t[s1Idx][s2Idx];
        int cnt = 0;
        if (text1[s1Idx] == text2[s2Idx])
        {
            cnt = 1 + solve(s1Idx + 1, s2Idx + 1, text1, text2, t);
        }
        else
        {
            cnt = max(solve(s1Idx + 1, s2Idx, text1, text2, t), solve(s1Idx, s2Idx + 1, text1, text2, t));
        }
        return t[s1Idx][s2Idx] = cnt;
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        // memoday
        // vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));
        vector<vector<int>> t(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        // return solve(0,0,text1,text2,t);
        return t[n][m];
    }
};
