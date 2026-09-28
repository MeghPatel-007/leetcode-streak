#include <bits/stdc++.h>
using namespace std;

// * recursion
class Solution
{
public:
    void insertAtBottom(stack<int> &st, int element)
    {
        if (st.empty())
        {
            st.push(element);
            return;
        }
        int topElement = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(topElement);
    }
    void solve(stack<int> &st)
    {
        if (st.empty())
            return;
        int top = st.top();
        st.pop();
        solve(st);
        insertAtBottom(st, top);
    }
    void reverseStack(stack<int> &st)
    {
        solve(st);
    }
};
