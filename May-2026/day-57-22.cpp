#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dp_string(vector<string> &result, string brackets, int open, int close, int n)
    {
        if (brackets.length() == 2 * n)
        {
            result.push_back(brackets);
            return;
        }
        if (open < n)
        {
            dp_string(result, brackets + "(", open + 1, close, n);
        }
        if (close < open)
        {
            dp_string(result, brackets + ")", open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        dp_string(result, "", 0, 0, n);
        return result;
    }
};
