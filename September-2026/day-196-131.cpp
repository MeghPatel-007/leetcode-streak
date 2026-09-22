#include <bits/stdc++.h>
using namespace std;

// * backtracking , dp , palindrome
class Solution
{
public:
    bool isPalindrome(string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void backtracking(int idx, string &s, vector<string> curr, vector<vector<string>> &result)
    {
        if (idx == s.length())
        {
            result.push_back(curr);
            return;
        }
        for (int i = idx; i < s.length(); i++)
        {
            if (isPalindrome(s, idx, i))
            {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtracking(i + 1, s, curr, result);
                curr.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> curr;
        backtracking(0, s, curr, result);
        return result;
    }
};
