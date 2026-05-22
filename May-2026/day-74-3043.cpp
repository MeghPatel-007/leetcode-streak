#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_set<string> st;

        for (int num : arr1)
        {
            string s = to_string(num);

            string pref = "";

            for (char c : s)
            {
                pref += c;
                st.insert(pref);
            }
        }

        int ans = 0;

        for (int num : arr2)
        {
            string s = to_string(num);

            string pref = "";

            for (char c : s)
            {
                pref += c;

                if (st.count(pref))
                {
                    ans = max(ans, (int)pref.size());
                }
            }
        }

        return ans;
    }
};
