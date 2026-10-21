#include <bits/stdc++.h>
using namespace std;

// * backtracking,BODMAS
class Solution
{
public:
    typedef long long ll;
    vector<string> ans;
    vector<string> addOperators(string num, int target)
    {
        solve(num, target, 0, "", 0, 0);
        return ans;
    }
    void solve(string s, int target, int idx, string selected, ll eval, ll last)
    {
        if (idx == s.length())
        {
            if (eval == target)
            {
                ans.push_back(selected);
            }
            return;
        }
        string currStr;
        ll digit = 0;
        for (int j = idx; j < s.length(); j++)
        {
            if (j > idx && s[idx] == '0')
                return;
            currStr += s[j];
            digit = digit * 10 + s[j] - '0';
            if (idx == 0)
            {
                solve(s, target, j + 1, selected + currStr, digit, digit);
            }
            else
            {
                solve(s, target, j + 1, selected + '+' + currStr, eval + digit, digit);
                solve(s, target, j + 1, selected + '-' + currStr, eval - digit, -digit);
                solve(s, target, j + 1, selected + '*' + currStr, (eval - last) + (last * digit), last * digit); //! imp equation
            }
        }
    }
};
