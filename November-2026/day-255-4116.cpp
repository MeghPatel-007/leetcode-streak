#include <bits/stdc++.h>
using namespace std;

// * array
class Solution
{
public:
    vector<string> assignUmbrella(vector<int> &rain)
    {
        int n = rain.size();
        vector<string> ans(n);
        int aCnt = 0, bCnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (rain[i] == 0)
            {
                ans[i] = "None";
                continue;
            }
            int alice = 0, bob = 0;
            if (rain[i] == 1 && rain[i + 1] == 1)
                alice = 1;
            if (rain[i] == 1)
                bob = 1;
            if (alice && bob)
            {
                if (aCnt <= bCnt)
                {
                    ans[i] = "Alice";
                    aCnt++;
                }
                else
                {
                    ans[i] = "Bob";
                    bCnt++;
                }
            }
            else if (alice)
            {
                ans[i] = "Alice";
                aCnt++;
            }
            else if (bob)
            {
                ans[i] = "Bob";
                bCnt++;
            }
        }
        rain[n - 1] == 1 ? ans[n - 1] = "Bob" : ans[n - 1] = "None";
        return ans;
    }
};
