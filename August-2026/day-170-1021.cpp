#include <bits/stdc++.h>
using namespace std;

// * Stack , String
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         string ans = "";
//         stack<int> st;
//         int n = s.length();
//         for(int i=0;i<n;i++){
//             if(s[i]=='('){
//                 if(!st.empty())ans += s[i];
//                 st.push(s[i]);
//             }else if(s[i] == ')' && st.top() == '('){
//                 st.pop();
//                 if(!st.empty())ans += s[i];
//             }
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int lvl = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                if (lvl > 0)
                    ans += ch;
                lvl++;
            }
            else if (ch == ')')
            {
                lvl--;
                if (lvl > 0)
                    ans += ch;
            }
        }
        return ans;
    }
};
