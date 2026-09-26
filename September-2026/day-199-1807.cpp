#include <bits/stdc++.h>
using namespace std;

// * hashmap
class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        unordered_map<string, string> m;
        int n = knowledge.size();
        for (int i = 0; i < n; i++)
        {
            m[knowledge[i][0]] = knowledge[i][1];
        }
        int len = s.size();
        string ans = "";
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                int start = i;
                while (s[i] != ')')
                {
                    i++;
                }
                string word = s.substr(start + 1, i - start - 1);
                if (m.find(word) != m.end())
                {
                    ans += m[word];
                }
                else
                {
                    ans += '?';
                }
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};
