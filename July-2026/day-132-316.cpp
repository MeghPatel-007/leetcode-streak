#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
                vector<bool> taken(26, false);
        vector<int> lastIndex(26, -1);
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            lastIndex[s[i] - 'a'] = i;
        }
        stack<char> st;
        for (int i = 0; i < n; i++)
        {

            if (taken[s[i] - 'a'])
                continue;
            // monotonic stack
            while (!st.empty() && s[i] < st.top() && lastIndex[st.top() - 'a'] > i)
            {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            taken[st.top() - 'a'] = true;
        }
        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
